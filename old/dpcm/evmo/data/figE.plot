set terminal latex
set label "S" at 104.762,0.0028972
set label "C" at 102.849,0.121426
set label "F" at 102.423,0.891538
plot [0:120][-0.2:1] 'figE.data' using 1:2:(10.0) smooth acsplines notitle, 'figE.data' using 1:3:(6.0) smooth acsplines notitle, 'figE.data' using 1:4:(10.0) smooth acsplines notitle
