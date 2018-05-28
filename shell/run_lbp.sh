#e engine
#p program
#g graph
#d debug level
#i max iteration
#t tolerance

engine="sync"
program="lbp"
graph="tiny"
debug=2
tol=0.01
iter='%'
show=false
opts=false
use_mpi=false
multi_h=false
run=true
ncpus=false
full=false

while getopts ":e:p:g:d:i:t:o-:" Option
do
  case $Option in
    e )
      engine=$OPTARG
      ;;
    p )
      program=$OPTARG
      ;;
    g )
      graph=$OPTARG
      ;;
    d )
      debug=$OPTARG
      ;;
    i )
      iter=$OPTARG
      ;;
    t )
      tol=$OPTARG
      ;;
    o )
      opts=true
      ;;      
    - )
      case $OPTARG in
          show )
            show=true
            ;;
          mpi1 )
            use_mpi=true
            multi_h=false
            ;;
          mpi3 )
            use_mpi=true
            multi_h=true
            ;;
          cpu )
            ncpus=true
            ;;
          norun )
            run=false
            ;;
          full )
            full=true
            ;;
      esac
      ;;
  esac
done


tag="${program}_${engine}_${graph}_${tol}_${iter}"

graph_path=" --graph /home/cjh/data/lbp/${graph}/synth_edata.tsv  \
--prior /home/cjh/data/lbp/${graph}/synth_vdata.tsv   "
to_run="./${program} --engine ${engine} \
        --graph_opts ingress=oblivious \
        ${graph_path}  --log_level ${debug}\
        --tol ${tol} \
        --output output/${tag}"

if [ "$opts" = true ]; then
  to_run="${to_run} --engine_opts goto_local_iter=${iter}"
fi

if [[ "${ncpus}" = true || "${multi_h}" = true ]]; then
  to_run="${to_run}  --ncpus 1"
fi


if [ "${use_mpi}" = true ]; then
  if [ "${multi_h}" = true ]; then
  	to_run="mpiexec -npernode 16 -H 10.3.1.14,10.3.1.15,10.3.1.16 ${to_run}"
  else
  	to_run="mpiexec -npernode 16 -H 10.3.1.16 ${to_run}"
  fi
fi

echo ${to_run}
if [ "$run" = true ]; then
  if [ "$show" = true ]; then
    if [ "$full" = true ]; then
      ${to_run} 2>& 1 |tee "./log/full_${tag}"
    else
      ${to_run} 2>& 1 |tee "./log/full_${tag}"|grep 'Active vertices' -A 2 -B 1
    fi     
  else
    ${to_run} 2>& 1 |cat >"./log/full_${tag}"
  fi

  numbers=($(cat "./log/full_${tag}"|grep -v 'local_cnt\|goto_local'|grep 'Active vertices' -A 2 -B 1 |grep -P ' [\d\.]*'  -o|sed '/^\s*$/d'))
  for i in $(seq 0 $((${#numbers[@]}-1)) )
  do
    printf ${numbers[$i]}'\t'  
    flag=$((i%4))
    if [[ $flag -eq 3 ]]; then
      echo ''
    fi
  done

  echo -e '\n'
  cat "./log/full_${tag}" |grep  'execute_time:'
  cat "./log/full_${tag}" |grep 'Final Runtime' > "./log/runtime_${tag}"
  #|tee "./log/runtime_${tag}"
  eval "cat output/${tag}.* > res/${tag}"
  eval "rm output/${tag}.*"

  if [ "${multi_h}" = false ]; then
  	cat "res/${tag}"|./synthetic_image_data --pred "denoising/${tag}.jpg" 2>& 1 >/dev/null
  	echo "http://10.3.1.16:8000/project/LazyGraph_all/LazyGraph/bin/denoising/${tag}.jpg"  	
  	rm "res/${tag}"
  fi  
fi
