cd cmake-build-debug/bin/

./interview > results.txt
./lcp >> results.txt
./todo >> results.txt
./session1000 >> results.txt
./session2000 >> results.txt
./session3000 >> results.txt

grep 'FAILED' results.txt