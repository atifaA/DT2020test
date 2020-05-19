#include "game/game.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>



void clipped_neigh_test(void){   
    struct board testBoard;
    testBoard.type_flag=CLIPPED_BOARD;
    testBoard.width=7;
    testBoard.height=4;
    (&testBoard)->cells = malloc(testBoard.height * sizeof(unsigned short *));
    for(int i = 0; i < testBoard.height; i++){
       (&testBoard)->cells[i] = malloc(testBoard.width * sizeof(unsigned short));
    }
    testBoard.cells[0][0]=0;     testBoard.cells[0][1]=1;     testBoard.cells[0][2]=0;     testBoard.cells[0][3]=0;     
    testBoard.cells[0][1]=1;     testBoard.cells[1][1]=0;     testBoard.cells[2][1]=1;     testBoard.cells[3][1]=0;
    testBoard.cells[0][2]=0;     testBoard.cells[1][2]=1;     testBoard.cells[2][2]=0;     testBoard.cells[3][2]=0;
    testBoard.cells[0][3]=0;     testBoard.cells[1][3]=0;     testBoard.cells[2][3]=0;     testBoard.cells[3][3]=1;
    testBoard.cells[0][4]=1;     testBoard.cells[1][4]=1;     testBoard.cells[2][4]=0;     testBoard.cells[3][4]=0;
    testBoard.cells[0][5]=0;     testBoard.cells[1][5]=1;     testBoard.cells[2][5]=1;     testBoard.cells[3][5]=1;
    testBoard.cells[0][6]=0;     testBoard.cells[1][6]=0;     testBoard.cells[2][6]=0;     testBoard.cells[3][6]=1;


    CU_ASSERT_EQUAL(neighbours_clipped(testBoard,4,2),5);
    CU_ASSERT_EQUAL(neighbours_clipped(testBoard,3,2),3);
    CU_ASSERT_EQUAL(neighbours_clipped(testBoard,6,1),2);

    for (int i = 0; i < testBoard.height; i++){
        free((&testBoard)->cells[i]);
    }
    free((&testBoard)->cells);
    

}


void neighbours_circular_test(void){
    struct board testBoard;
    testBoard.type_flag=CIRCULAR_BOARD;
    testBoard.width=7;
    testBoard.height=4;
    (&testBoard)->cells = malloc(testBoard.height * sizeof(unsigned short *));
    for(int i = 0; i < testBoard.height; i++){
       (&testBoard)->cells[i] = malloc(testBoard.width * sizeof(unsigned short));
    }
    testBoard.cells[0][0]=0;     testBoard.cells[1][0]=1;     testBoard.cells[2][0]=0;     testBoard.cells[3][0]=0;     
    testBoard.cells[0][1]=1;     testBoard.cells[1][1]=0;     testBoard.cells[2][1]=1;     testBoard.cells[3][1]=0;
    testBoard.cells[0][2]=0;     testBoard.cells[1][2]=1;     testBoard.cells[2][2]=0;     testBoard.cells[3][2]=0;
    testBoard.cells[0][3]=0;     testBoard.cells[1][3]=0;     testBoard.cells[2][3]=0;     testBoard.cells[3][3]=1;
    testBoard.cells[0][4]=1;     testBoard.cells[1][4]=1;     testBoard.cells[2][4]=0;     testBoard.cells[3][4]=0;
    testBoard.cells[0][5]=0;     testBoard.cells[1][5]=1;     testBoard.cells[2][5]=1;     testBoard.cells[3][5]=1;
    testBoard.cells[0][6]=0;     testBoard.cells[1][6]=0;     testBoard.cells[2][6]=0;     testBoard.cells[3][6]=1;
        
    CU_ASSERT_EQUAL(neighbours_circular(testBoard,0,3),3);
    CU_ASSERT_EQUAL(neighbours_circular(testBoard,4,0),4);
    CU_ASSERT_EQUAL(neighbours_circular(testBoard,3,3),1);
   for (int i = 0; i < testBoard.height; i++){
        free((&testBoard)->cells[i]);
    }
    free((&testBoard)->cells);
}



int main (){


        CU_pSuite suite = NULL;

        if(CUE_SUCCESS != CU_initialize_registry()){
            return CU_get_error();
        }


        suite = CU_add_suite("game_test", NULL, NULL);

        if(NULL == suite){
            CU_cleanup_registry();
            return CU_get_error();
        }


        if( (NULL == CU_add_test(suite, "clipped_neigh_test", clipped_neigh_test))
                     ||
            (NULL == CU_add_test(suite, "neighbours_circular_test", neighbours_circular_test))
        
        ){

                CU_cleanup_registry();
                return CU_get_error();
            }
            
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();

        return CU_get_error();


}
    