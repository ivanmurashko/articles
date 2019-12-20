set terminal latex
set label "C" at  757.598,0.16632
set label "F" at 757.598,0.34
set label "S" at 761.14,0.5
plot [0:2000][0:1] 'figZh.data' using 1:2:(1.0) smooth acsplines notitle with lines lt 1, 'figZh.data' using 1:3:(1.0) smooth acsplines notitle with lines lt 1, 'figZh.data' using 1:4:(1.0) smooth acsplines notitle with lines lt 1
