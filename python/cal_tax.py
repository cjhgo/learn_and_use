

susuan_kouchu=[
  0,
  36000*0.03-36000*0.1,
  36000*0.03+(144000-36000)*0.1-144000*0.2,
  36000*0.03+(144000-36000)*0.1+(300000-144000)*0.2-300000*0.25,
  36000*0.03+(144000-36000)*0.1+(300000-144000)*0.2+(420000-300000)*0.25-420000*0.3,
  36000*0.03+(144000-36000)*0.1+(300000-144000)*0.2+(420000-300000)*0.25+(660000-420000)*0.3-660000*0.35,
  36000*0.03+(144000-36000)*0.1+(300000-144000)*0.2+(420000-300000)*0.25+(660000-420000)*0.3+(960000-660000)*0.35-960000*0.45
]

def findrange(n):
  tax_split=[36000,144000,300000,420000,660000,960000]
  if n <= 36000:
    return 0
  elif n <= 144000:
    return 1
  elif n <= 300000:
    return 2
  elif n <= 420000:
    return 3
  elif n <= 660000:
    return 4
  elif n <= 960000:
    return 5
  else:
    return 6
def rate_function(n):  
  tax_rate=[0.03,0.1,0.2,0.25,0.3,0.35,0.45]
  index = findrange(n)
  return index, tax_rate[index]    
def tax_function(n):
  if n <= 36000:
    return n*0.03
  elif n <= 144000:
    return 36000*0.03+\
            (n-36000)*0.1
  elif n <= 300000:
    return 36000*0.03+\
            (144000-36000)*0.1+\
              (n-144000)*0.2
  elif n <= 420000:
    return 36000*0.03+\
            (144000-36000)*0.1+\
              (300000-144000)*0.2+\
                (n-300000)*0.25
  elif n <= 660000:
      return 36000*0.03+\
          (144000-36000)*0.1+\
            (300000-144000)*0.2+\
              (420000-300000)*0.25+\
                (n-420000)*0.3
  elif n <= 960000:
      return 36000*0.03+\
          (144000-36000)*0.1+\
            (300000-144000)*0.2+\
              (420000-300000)*0.25+\
                (660000-420000)*0.3+\
                  (n-660000)*0.35
  else:
      return 36000*0.03+\
          (144000-36000)*0.1+\
            (300000-144000)*0.2+\
              (420000-300000)*0.25+\
                (660000-420000)*0.3+\
                  (960000-660000)*0.35+\
                    (n-960000)*0.45
def calcul_tax(n):
  index,rate=rate_function(n)
  tax = n*rate+susuan_kouchu[index]
  return tax

def gentax(salary):
  shebao=25401*(0.08+0.02+0.12+0.002)
  base = 5000
  salary_tax = salary-shebao-base  
  print(salary,shebao,salary_tax)
  sum = 0
  sum_cash=0
  sumtax=0
  for i in range(12):
    temp = tax_function(sum)
    sum += salary_tax
    temp2 = tax_function(sum)
    delta = temp2- temp
    cash_i = salary-shebao-delta
    sum_cash+= cash_i
    print i,sum_cash,cash_i, delta
    sumtax += delta
  print sumtax,sumtax/12.0

import matplotlib.pyplot as plt

def plot_graph():
  x=[]
  y1=[]
  y2=[]
  for i in range(1000):
    v = i*1000
    x.append(v)
    y1.append(tax_function(v))

    y2.append(rate_function(v)[1])
  print x,y1,y2
  color = 'tab:red'
  fig, ax1 = plt.subplots()
  ax1.set_xlabel(u"income for tax")
  ax1.set_ylabel(u"money for tax")  
  ax1.plot(x, y1)
  ax2 = ax1.twinx()
  ax2.set_ylabel(u"rate for tax")  
  ax2.plot(x, y2)
  plt.show()

if __name__ == "__main__":
  gentax(20000)
  # plot_graph()