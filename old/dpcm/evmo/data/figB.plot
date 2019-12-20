set terminal latex
set label "$\\Gamma d = 4.2$" at 146,-0.5
set label "$\\Gamma d = 4.02$" at 1460,-1.8
set label "$\\Gamma d = 4$" at 1629,-5
set label "$t$" at 2005,-10.6
set label "$log_10 I/I_0$" at -120,0
set style line 1 lt 2 lw 2 pt 3 ps 0.5
plot [0:2000][-10:0] 'figB5.data' using 1:(log($3)/log(10)) ls 1 notitle, 'figB4.data' using 1:(log($3)/log(10)) ls 1 notitle, 'figB6.data' using 1:(log($3)/log(10)) ls 1 notitle