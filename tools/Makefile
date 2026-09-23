default:# torch
	@$(CC) n64crc.c -o n64crc
	@make  -C ido-static-recomp/ setup
	@make  -C ido-static-recomp/ VERSION=5.3
	@$(CC) -Wno-multichar moduleTool.c -o moduleTool
	@make -C daisybox
	@make -C daisybox genForm0
	@cp daisybox/genForm0 .
	@make -C rabbitizer
	@$(CC) -I rabbitizer/include -O2 -Wall moduleCompare.c -Lrabbitizer/build -lrabbitizer -o moduleCompare
	@printf "done\n"

clean:
	rm n64crc
