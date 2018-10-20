: <<'eof'
use heredoc to input multile line
use hereoc+ : command to comment multil line
eof

cat <<end
c++ primer data structure
algorithm nlp dl machine learing 
${PWD}
end

echo -e "\n\n"

cat <<'eof'
c++ primer data structure
algorithm nlp dl machine learing 
${PWD}
eof

: <<comment
You will live a long, healthy, happy life and make bags of money.
All the troubles you have will pass \${PWD}
 away very quickly. ' jskdf 
abc
comment
fortune|cowsay