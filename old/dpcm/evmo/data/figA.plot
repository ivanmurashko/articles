set terminal latex
set label "S" at 18.367,0.831471
set label "F" at 24.7,0.23
set label "C" at 80,0.333192
set label "$t$" at 100,-0.06
set label "$I/I_0$" at -7,1.0
plot [0:100][0:1] 'figA.data' using 1:2:(1.0) smooth acsplines notitle  with lines lt 1, 'figA.data' using 1:3:(1.0) smooth acsplines notitle  with lines lt 1, 'figA.data' using 1:4:(1.0) smooth acsplines notitle with lines lt 1

