all: test

# Where to install
INSIDIR = ../bin

test: homework4.c ../incl/bitmap.h
# 	gcc -o test homework4.c -lm -O2
	gcc -o test homework4.c -lm

install: test
	cp test $(INSIDIR);\
	rm test;

pic: install
# 	for iteration_times in {20 40 70 100};do\
#		echo "$(iteration_times)";\这居然总是显示空字符串
# 		./test res_$(iteration_times).bmp -0.75 0 1.7 40;\
# 		convert res_$(iteration_times).bmp res_$(iteration_times).png;\
# 		cp res_$(iteration_times).png ../examples/res_$(iteration_times).png;\
# 		rm res_$(iteration_times).bmp res_$(iteration_times).png;\
# 	done;
# 	./test res_20.bmp -0.75 0 1.7 20;\
# 	convert res_20.bmp res_20.png;\
# 	cp res_20.png ../examples/res_20.png;\
# 	rm res_20.bmp res_20.png;
# 	./test res_40.bmp -0.75 0 1.7 40;\
# 	convert res_40.bmp res_40.png;\
# 	cp res_40.png ../examples/res_40.png;\
# 	rm res_40.bmp res_40.png;
# 	./test res_100.bmp -0.75 0 1.7 100;\
# 	convert res_100.bmp res_100.png;\
# 	cp res_100.png ../examples/res_100.png;\
# 	rm res_100.bmp res_100.png;
# 	./test res_400.bmp -0.75 0 1.7 400;\
# 	convert res_400.bmp res_400.png;\
# 	cp res_400.png ../examples/res_400.png;\
# 	rm res_400.bmp res_400.png;
# 	./test res_5000.bmp -0.75 0 1.7 5000;\
# 	convert res_5000.bmp res_5000.png;\
# 	cp res_5000.png ../examples/res_5000.png;\
# 	rm res_5000.bmp res_5000.png;
	../bin/test res_color_400.bmp -0.75 0 1.7 400;\
	convert res_color_400.bmp res_color_400.png;\
	cp res_color_400.png ../examples/res_color_400.png;\
	rm res_color_400.bmp res_color_400.png;

report: ../doc/homework4.tex
	cd ../ && xelatex ./doc/homework4.tex;\
	bibtex homework4;\
	xelatex ./doc/homework4.tex;\
	xelatex ./doc/homework4.tex;\
	cp homework4.pdf ./doc/homework4.pdf;\
	rm homework4.aux homework4.bbl homework4.blg homework4.log homework4.pdf;\