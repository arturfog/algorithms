all: sort

sort: sort.go
	go build -o $@ $^

clean:
	rm -f sort

run: sort
	@./sort

.PHONY: all clean