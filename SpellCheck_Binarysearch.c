// Created by RitsukiShuto on 2020/07/30-13:06:35.
// SpellCheck_Binarysearch.c
// Coding 'Shift JIS'
//
#include<stdio.h>
#include<time.h>
#define SIZE_OF_DICT 2000

int main(void){
    /* 時間測定用 */
    clock_t start, end;

    int dict[SIZE_OF_DICT];     // dictionary.txtを格納
    int word;            // dict例示用

    int left, right, mid;       // 二分探索用
    int cnt = 0;                // スペルミスカウンタ

    FILE *fp_dict = fopen("dictionary.txt", "r");    // dictionary.txtのfp_dictを宣言
    FILE *fp_sct = fopen("script.txt", "r");

//    fscanf(fp_dict, "%d", &word);      // 1番目の整数を例示
//    printf("%d\n", word);

    /* 配列にdictionary.txtを格納 */
    for(int i = 0; i < SIZE_OF_DICT; i++){
        fscanf(fp_dict, "%d", &(dict[i]));
    }

//    printf("dict[10] = %d\n", dict[10]);       // 10番目の整数を例示

    /* スペルチェック開始 */
    start = clock();    // 測定開始

    while(fscanf(fp_sct, "%d", &word) == 1){
        left = 0;
        right = SIZE_OF_DICT - 1;

        while(left < right){
            mid = (left + right) / 2;

            if (dict[mid] == word){
                left = mid;
                right = mid;
            }else if(dict[mid] < word){
                left = mid + 1;
                cnt++;
            }else{
                right = mid - 1;
                cnt++;
            }
        }
    }

    /* 結果を表示 */
    printf("スペルミス件数 = %d件\n", cnt);

    fclose(fp_dict);
    fclose(fp_sct);

    end = clock();
    printf("実行時間:%.2f(s)\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}