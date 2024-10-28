GPP = g++
GPP_FLS = -Wall

SRC = $(wildcard *.cpp)
OUT = main.out

$(OUT):
	$(GPP) $(GPP_FLS) $(SRC) -o $@

run: $(OUT)
	./$<

clean: $(OUT)
	@rm $<
