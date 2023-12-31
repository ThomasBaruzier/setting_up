#!/bin/bash

cd ..
echo
make fast || exit

echo -e '\n\e[34mSTARTING TESTS\e[0m\n'

tests() {
    fails=0

    for map in tests/maps/*; do
        solution="${map/tests\/maps/tests\/solved}"
        echo -n "Testing '${map#*/}' against '${solution#*/}': "
        result=$(valgrind ./setting_up "$map" 2>tmp | cat -e)
        truth=$(cat -e "$solution")
        if [ "$result" != "$truth" ]; then
            echo -e '\e[31mFAIL\e[0m'
            echo "$result" > tests/result
            echo "$truth" > tests/truth
            ((fails++))
        else
            echo -e '\e[32mVALID\e[0m'
            cat tmp | grep 'errors from'
        fi
    done
}

time tests

[ "$fails" -gt 0 ] && \
echo -e "\n\e[31m$fails TESTS FAILED!!\e[0m\n" || \
echo -e '\n\e[32mALL TESTS VALID\e[0m\n'
rm tmp
make fclean
