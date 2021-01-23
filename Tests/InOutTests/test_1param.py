import subprocess
import os
import sys


output_oneParam = "Tests/InOutTests/outOneParam.csv"

with open(output_oneParam, 'w') as output_f:
    output_f.write("double; Fpn; method; (double)result; (Fpn)result ") 
    
    i = -100.0
    while (i<100):
        i += 1.01
        print (i)
        subprocess.run(["sudo","./main", str(i) ], stdout=output_f, stderr=output_f)


