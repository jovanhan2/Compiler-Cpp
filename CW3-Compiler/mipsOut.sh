echo "========================================"
echo "Assembl .s to object"

cat test.c
mips-linux-gnu-gcc -S test.c
cat test.s
