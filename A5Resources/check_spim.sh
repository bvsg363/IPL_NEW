#!/bin/bash
clear

pass=0
fail=0
pass2=0
fail2=0
pass3=0
fail3=0
pass4=0
fail4=0


for i in $(find TestCases -name "test2.c");
do 
    ./sclp_old -ast -symtab -icode $i # sclp_old
    cp $i.ast test_ast_old.txt
    cp $i.spim test_spim_old.txt
    cp $i.sym test_symtab_old.txt
    cp $i.ic test_icode_old.txt

    ./sclp_new -ast -symtab -icode $i # sclp_new
    cp $i.ast test_ast_new.txt
    cp $i.spim test_spim_new.txt
    cp $i.sym test_symtab_new.txt
    cp $i.ic test_icode_new.txt

    #--------test_ast----------
    
    DIFF=$(diff test_ast_old.txt test_ast_new.txt) 
    if [ "$DIFF" == "" ] 
    then
    pass=$((pass+1))
     echo "Passed $i ast"
   
    else
    fail=$((fail+1))
    echo "Failed $i ast"
    fi

    #-----------test_spim---------------
    DIFF1=$(diff test_spim_old.txt test_spim_new.txt) 
    if [ "$DIFF1" == "" ] 
    then
    pass2=$((pass2+1))
     echo "Passed $i spim"
    
    else
    fail2=$((fail2+1))
    echo "Failed $i spim"
    fi

    #----------------test_symtab------------

    DIFF2=$(diff test_symtab_old.txt test_symtab_new.txt) 
    if [ "$DIFF2" == "" ] 
    then
    pass3=$((pass3+1))
     echo "Passed $i symtab"
    
    else
    fail3=$((fail3+1))
    echo "Failed $i symtab"
    fi

    #----------------test_icode---------------

    DIFF2=$(diff test_icode_old.txt test_icode_new.txt) 
    if [ "$DIFF2" == "" ] 
    then
    pass4=$((pass4+1))
     echo "Passed $i icode"
    
    else
    fail4=$((fail4+1))
    echo "Failed $i icode"
    fi

    echo -e "-------------------\n\n"
    
    rm $i.ast
    rm $i.spim
    rm $i.sym
    rm $i.ic

done
#rm test_ast_old.txt
#rm test_ast_new.txt

echo -e "Passed Cases $pass ast"
echo -e "Failed Cases $fail ast\n"

echo -e "Passed Cases $pass2 spim"
echo -e "Failed Cases $fail2 spim\n"

echo -e "Passed Cases $pass3 symtab"
echo -e "Failed Cases $fail3 symtab\n"

echo -e "Passed Cases $pass4 icode"
echo -e "Failed Cases $fail4 icode\n"
