set terminal latex
set label "$M_f = 7.4 \\cdot 10^{-5}$" at 9.94741,0.0400715
set label "$M_f = 7 \\cdot 10^{-5}$" at 9.91907,0.152554
set label "$M_f = 6 \\cdot 10^{-5}$" at 12.936,0.29936
set label "$M_f = 5 \\cdot 10^{-5}$" at 13.8303,0.484082
plot 'figD1.data' using 1:2:(1.0) smooth acsplines notitle with lines lt 1, 'figD2.data' using 1:2:(1.0) smooth acsplines notitle with lines lt 1, 'figD3.data' using 1:2:(1.0) smooth acsplines  notitle with lines lt 1, 'figD4.data' using 1:2:(1.0) smooth acsplines notitle with lines lt 1
