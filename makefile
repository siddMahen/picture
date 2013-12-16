PHONY: all

all:
	clang main.c -o picture -03 -ffast-math -lm -lpicam -lmmal -lvcos -lbcm_host

clean:
	rm picture

install:
	cp ./picture /usr/local/bin
