int Edit_Dist( ){
 for(int i = 0; i <= max(la, lb); i ++)
  C[0][i] = i, C[i][0] = i;

 for(int i = 1; i <= la; i ++)
  for(int j = 1; j <= lb; j ++)
   if(A[i] == B[j] && C[i - 1][j - 1] != 1 << 30)
    C[i][j] = C[i - 1][j - 1];
   else{
    C[i][j] = 1 << 30;
    C[i][j] = min(C[i][j], C[i - 1][j] + 1);
    C[i][j] = min(C[i][j], C[i][j - 1] + 1);
    C[i][j] = min(C[i][j], C[i - 1][j - 1] + 1);
   }

   return C[la][lb];
}

