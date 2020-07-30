// Created by RitsukiShuto on 2020/07/30-13:06:35.
// SpellCheck_Biunarysearch.c
// Coding 'Shift JIS'
//
#include<stdio.h>
#include<time.h>

int main(void){
    /* ���ԑ���p */
    clock_t start, end;

    int dict[2000];     // dictionary.txt���i�[
    int word;            // dict�Ꭶ�p

    int left, right, mid;       // �񕪒T���p
    int cnt = 0;                // �X�y���~�X�J�E���^

    FILE *fp_dict = fopen("dictionary.txt", "r");    // dictionary.txt��fp_dict��錾
    FILE *fp_sct = fopen("script.txt", "r");

//    fscanf(fp_dict, "%d", &word);      // 1�Ԗڂ̐�����Ꭶ
//    printf("%d\n", word);

    /* �z���dictionary.txt���i�[ */
    for(int i = 0; i < 2000; i++){
        fscanf(fp_dict, "%d", &(dict[i]));
    }

//    printf("dict[10] = %d\n", dict[10]);       // 10�Ԗڂ̐�����Ꭶ

    /* �X�y���`�F�b�N�J�n */
    start = clock();    // ����J�n

    while(fscanf(fp_sct, "%d", &word) == 1){
        left = 0;
        right = 2000;

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

    /* ���ʂ�\�� */
    printf("�X�y���~�X���� = %d��\n", cnt);

    fclose(fp_dict);
    fclose(fp_sct);

    end = clock();
    printf("���s����:%.2f(s)\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}