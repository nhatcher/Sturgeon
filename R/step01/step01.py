surv = [float(line) for line in open('surv.csv')]
fecund = [float(line) for line in open('fecund.csv')]
abundb = [float(line) for line in open('initabundance.csv')]
for iii in range(1,101):
  spawn = [i*j for i,j in zip(abundb,fecund)]
  spawnb = [x * 0.0001 for x in spawn]
  spawntot = sum(spawnb)
  abunda = [i*j for i,j in zip(abundb,surv)]
  for j in range(1,79):
    abundb[j] = abunda[j-1]
  abundb[0] = spawntot
  print(sum(abundb[14:]))
