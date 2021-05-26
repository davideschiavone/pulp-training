Results should be:

Total mathematical MAC: 256 outputs pixel * 25 MAC = 6400 MAC


rv32imcxpulp dotp
CYCLES: 7626
INSTR: 7154
MAC/CYCLES = 0.84
CYCLES/PIXEL = 29.79 (x5.03)
example execution time at 600MHz = 7626/600 us = 12.71 us

rv32imcxpulp
CYCLES: 21307
INSTR: 15691
MAC/CYCLES = 0.30
CYCLES/PIXEL = 83.23 (x1.8)
example execution time at 600MHz = 21307/600 us = 35.51 us

rv32imc
CYCLES: 38390
INSTR: 30208
MAC/CYCLES = 0.17
CYCLES/PIXEL = 149.96
example execution time at 600MHz = 38390/600 us = 63.98 us

Run on the latest PULPissimo on May 26 2021