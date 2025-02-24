g++ -o ccat ccat.cpp
./ccat tests/test.txt tests/test2.txt > test_output.txt
sed G tests/test.txt | ./ccat -n | head >> test_output.txt
sed G tests/test.txt | ./ccat -b | head -n5 >> test_output.txt
diff test_output.txt tests/reference.txt
if [ $? -eq 0 ]; then
    echo "Setup Done!"
else
    echo "Tests failed - outputs don't match"
fi
#rm test_output.txt