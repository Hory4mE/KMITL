// 64050156 พงศธร ธุระเสร็จ
// Q1.6 worker1 Thread 15 x value = 3 , worker2 Tread 16 x value = 7
import java.util.Arrays;

public class L7_MatrixMul {
    public static void main(String[] args) {
        int[][] mat1 = {{5,6,7},
                        {4,8,9}};
        int[][] mat2 = {{6,4},
                        {5,7},
                        {1,1}};
        MyData matA = new MyData(mat1);
        MyData matB = new MyData(mat2);
        int matC_r = matA.data.length;
        int matC_c = matB.data[0].length;
        MyData matC = new MyData(matC_r, matC_c);
        Thread[][] thd = new Thread[matC_r][matC_r];
        /* Q4 */
        for(int i = 0 ; i < matC_r;i++){
            for(int j = 0 ; j < matC_c;j++){
                thd[i][j] = new Thread(new MatrixMulThread(i, j, matA, matB, matC));
                thd[i][j].start();
            }
        }

        /* Q5 */
        try{
            for(int i = 0 ; i < thd.length;i++){
                for(int j = 0 ; j < thd.length;j++){
                    thd[i][j].join();
                }
            }

        }catch(Exception e){
            System.out.println(e);
            System.out.println("Matrix Error at here");
        }
        matC.show();
    }
}

class MatrixMulThread implements Runnable{
    int processing_row;
    int processing_col;
    MyData datA,datB,datC;
    int sum=0;
    MatrixMulThread(int tRow, int tCol, MyData a, MyData b, MyData c){
        /* Q1 */
        processing_row = tRow;
        processing_col = tCol;
        datA = a;datB = b;datC = c;
    }
    /*Q2*/public void run(){

    /*Q3*/ 
    for(int i = 0; i < datA.data[0].length;i++){
            // System.out.print(datC.data[processing_row][processing_col]+" += "+ datA.data[processing_row][i] * datB.data[i][processing_col]+" j = "+processing_col+" i = "+i+" |");
            datC.data[processing_row][processing_col] += datA.data[processing_row][i] * datB.data[i][processing_col];
        }
        System.out.println(sum);
    }
    
}

class MyData{
    int[][] data;
    MyData(int[][] mainmat){ // set main matrix to mulipy
        data = mainmat;
    }
    MyData(int r, int c){ // create Empty Matrix
        data = new int[r][c];
        for(int[] row : data){
            Arrays.fill(row, 0);
        }
    }
    void show(){
        System.out.println(Arrays.deepToString(data));
    }
}
