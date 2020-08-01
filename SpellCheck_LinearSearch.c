// Created by RitsukiShuto on 2020/07/30-13:06:35.
// SpellCheck_Binarysearch.c
// Coding 'Shift JIS'
//
#include<stdio.h>
#include<time.h>
#define SIZE_OF_DICT 2000

int main(void){
    /* ���ԑ���p */
    clock_t start, end;

    int dict[SIZE_OF_DICT];     // dictionary.txt���i�[
    int word;                   // dict�Ꭶ�p

    int MissMatch_Words = 0;    // �X�y���~�X�J�E���^

    FILE *fp_dict = fopen("dictionary.txt", "r");    // dictionary.txt��fp_dict��錾
    FILE *fp_sct = fopen("script.txt", "r");

//    fscanf(fp_dict, "%d", &word);      // 1�Ԗڂ̐�����Ꭶ
//    printf("%d\n", word);

    /* �z���dictionary.txt���i�[ */
    for(int i = 0; i < SIZE_OF_DICT; i++){
        fscanf(fp_dict, "%d", &(dict[i]));
    }

//    printf("dict[10] = %d\n", dict[10]);       // 10�Ԗڂ̐�����Ꭶ

    /* �X�y���`�F�b�N�J�n */
    start = clock();    // ����J�n

    /* ���`�����@ */
    while(fscanf(fp_sct, "%d", &word) == 1){
        int Match_Words_Flag = 0;

        for(int i = 0; i < SIZE_OF_DICT; i++){
            if(word == dict[i]){
                // Match_Words++;
                Match_Words_Flag = 1;
                break;
            }
        }

        if(Match_Words_Flag == 0){
            MissMatch_Words++;
        }

        Match_Words_Flag = 0;
    }
    // MissMatch_Words = Checked_Words - Match_Words;     // �X�y���~�X�������v�Z

    /* ���ʂ�\�� */
    printf("�X�y���~�X���� = %d��\n", MissMatch_Words);

    fclose(fp_dict);
    fclose(fp_sct);

    end = clock();
    printf("���s����:%.2f(s)\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}