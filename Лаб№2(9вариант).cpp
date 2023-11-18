#include <iostream>

int main() {
    int N, M;

    // ���� ������� �������
    std::cout << "Input size matrix(N and M): ";
    std::cin >> N >> M;

    // �������� ������������ ������� �������� NxM
    int** unsorted_matrix = new int* [N];
    for (int i = 0; i < N; i++) {
        unsorted_matrix[i] = new int[M];
    }

    // ���� ��������� �������
    std::cout << "Input the matrix elements:" << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << "Input matrix[" << i+1 << "][" << j+1 << "]:";
            std::cin >> unsorted_matrix[i][j];
        }
    }

    // ����� ����������������� �������
    std::cout << "Output unsorted matrix:" << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << unsorted_matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // �������� ������������� ������� �������� M ��� �������� ���������� ��������� ��������
    int* min_Elements = new int[M];

    //����� ����������� ��������� ��������
    for (int j = 0; j < M; j++) {
        min_Elements[j] = unsorted_matrix[0][j];
        for (int i = 1; i < N; i++) {
            if (unsorted_matrix[i][j] < min_Elements[j]) {
                min_Elements[j] = unsorted_matrix[i][j];
            }
        }

    }

    //�������� ������� ��� ����������
    int** sorted_Matrix = new int* [N];
    for (int i = 0; i < N; i++) {
        sorted_Matrix[i] = new int[M];
    }

    // ����������� ��������
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N; i++) {
            sorted_Matrix[i][j] = unsorted_matrix[i][j];
        }
    }

    //���������� �������
    for (int i = 0; i < M - 1; i++) {
        int min = i;
        for (int j = i + 1; j < M; j++) {
            if (min_Elements[j] < min_Elements[min]) {
                min = j;
            }
        }

        for (int g = 0; g < N; g++) {
            int t = sorted_Matrix[g][i];
            sorted_Matrix[g][i] = sorted_Matrix[g][min];
            sorted_Matrix[g][min] = t;

        }
        int a = min_Elements[i];
        min_Elements[i] = min_Elements[min];
        min_Elements[min] = a;

    }


    
    // ����� ��������������� �������
    std::cout << "Sorted matrix:" << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << sorted_Matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    

    // ������������ ������
    for (int i = 0; i < N; i++) {
        delete[] unsorted_matrix[i];
        delete[] sorted_Matrix[i];
    }
    delete[] unsorted_matrix;
    delete[] sorted_Matrix;
    delete[] min_Elements;

    return 0;
}
