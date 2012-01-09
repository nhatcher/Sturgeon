# Uncomment for windows
# fecund <- as.vector(read.table("d:/fecund.csv", sep=","))
# surv <- as.vector(read.table("d:/surv.csv", sep=","))
# abundb <- as.vector(read.table("d:/initabundance.csv", sep=","))
fecund <- as.vector(read.table("fecund.csv", sep=","))
surv <- as.vector(read.table("surv.csv", sep=","))
abundb <- as.vector(read.table("initabundance.csv", sep=","))
for (iii in c(1:100)) {
   spawn <- abundb * fecund
   spawn <- spawn * 0.0001
   spawntot <- as.vector(sum(spawn))
   abunda <- abundb * surv
   for (i in c(2:80)) {
      abundb[i,1] <- abunda[(i-1),1]
   }
   abundb[1,1] <- spawntot
   print(sum(abundb[15:80,1]))
}
