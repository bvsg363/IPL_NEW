#!/bin/bash
clear

pass=0
fail=0
pass2=0
fail2=0
pass3=0
fail3=0


for i in $(find TestCases -name "*.c"); 
do 
    ./sclp_old -ast -symtab -eval $i # sclp_old
    cp $i.ast test_ast_old.txt
    cp $i.eval test_eval_old.txt
    cp $i.sym test_symtab_old.txt

    ./sclp_new -ast -symtab -eval $i # sclp_new
    cp $i.ast test_ast_new.txt
    cp $i.eval test_eval_new.txt
    cp $i.sym test_symtab_new.txt

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

    #---------------test_eval------------

    DIFF2=$(diff test_eval_old.txt test_eval_new.txt) 
    if [ "$DIFF2" == "" ] 
    then
    pass2=$((pass2+1))
     echo "Passed $i eval"
    
    else
    fail2=$((fail2+1))
    echo "Failed $i eval"
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

    echo -e "-------------------\n\n"
    
    rm $i.ast
    rm $i.eval
    rm $i.sym

done
#rm test_ast_old.txt
#rm test_ast_new.txt

echo -e "Passed Cases $pass ast"
echo -e "Failed Cases $fail ast\n"

echo -e "Passed Cases $pass2 eval"
echo -e "Failed Cases $fail2 eval\n"

echo -e "Passed Cases $pass3 symtab"
echo -e "Failed Cases $fail3 symtab"