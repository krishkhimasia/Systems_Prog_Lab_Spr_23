
Q1)

(a) Delete in increasing order.
```valgrind
==96756== HEAP SUMMARY:
==96756==     in use at exit: 144 bytes in 9 blocks
==96756==   total heap usage: 10 allocs, 1 frees, 1,168 bytes allocated
==96756== 
==96756== LEAK SUMMARY:
==96756==    definitely lost: 16 bytes in 1 blocks
==96756==    indirectly lost: 112 bytes in 7 blocks
==96756==      possibly lost: 0 bytes in 0 blocks
==96756==    still reachable: 16 bytes in 1 blocks
==96756==         suppressed: 0 bytes in 0 blocks
```
(b) Delete in descending order.
```valgrind
==96672== HEAP SUMMARY:
==96672==     in use at exit: 144 bytes in 9 blocks
==96672==   total heap usage: 10 allocs, 1 frees, 1,168 bytes allocated
==96672== 
==96672== LEAK SUMMARY:
==96672==    definitely lost: 128 bytes in 8 blocks
==96672==    indirectly lost: 0 bytes in 0 blocks
==96672==      possibly lost: 0 bytes in 0 blocks
==96672==    still reachable: 16 bytes in 1 blocks
==96672==         suppressed: 0 bytes in 0 blocks
```
