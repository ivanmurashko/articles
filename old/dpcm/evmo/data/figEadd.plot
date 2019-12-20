set terminal latex
set label "S" at 80,-13.6
set label "C" at 80,-1.6
set label "F" at 80,0.6
set style line 1 lt 2 lw 2 pt 3 ps 0.5
plot [0:100][-25:2] 'figE.data' using 1:(log($2)) ls 1  notitle, 'figE.data' using 1:(log($3)) ls 1  notitle, 'figE.data' using 1:(log($4)) ls 1 notitle
