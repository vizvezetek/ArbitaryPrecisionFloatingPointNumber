import subprocess
import os
import sys

output_twoParam = "Tests/InOutTests/outTwoParam.csv"

with open(output_twoParam, 'w') as output_f:
    output_f.write("double1;double2;Fpn1;Fpn2; method; (double)result; (Fpn)result ") 

    i = -100.0
    while (i<100):
        
        j = -100.0
        while (j<100):
            j += 1.01
            print (i,' ',j)
            subprocess.run(["sudo","./main", str(i), str(j) ], stdout=output_f, stderr=output_f)
        i += 1.01