set terminal latex
set label "$\\Gamma d = 4.96$" at 1500,-6.5
set label "$\\Gamma d = 5$" at 1500,-1.6
set label "$\\Gamma d = 6$" at 150,-1
set label "$t$" at 2000,-10.6
set label "$lg I/I_0$" at -100,0
set style line 1 lt 2 lw 2 pt 3 ps 0.5
plot [0:2000][-10:0] 'figV1.data' using 1:(log($3)/log(10)) ls 1 notitle, 'figV2.data' using 1:(log($3)/log(10)) ls 1 notitle, 'figV3.data' using 1:(log($3)/log(10)) ls 1 notitle