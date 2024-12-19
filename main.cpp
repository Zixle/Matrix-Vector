#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
// the amount of slots in the vector will be equal to the amount of coloumns in matrix
// Function using indexing
vector<int> Index( vector<vector<int>>& matrix , vector<int>& vector ) {
   
    int m_size = static_cast<int>(matrix.size());
    int v_size = static_cast<int>(vector.size());
   
    std::vector<int>result(m_size, 0 ); // all slots intialized to zero
    
    for (int i = 0; i < m_size; i++){ // amount of vectors in matrix
        for (int j = 0; j < v_size; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }
    

    //cout << result.size() << endl;
    return result;
}

// Function using iterators
vector<int> Iterator( vector<vector<int>>& matrix , vector<int>& vector) {
    
    int m_size = static_cast<int>(matrix.size()); // amount of vectors in vector
    int v_size = static_cast<int>(vector.size()); // will be equal to slots in each vector
    
    std::vector<int>result(m_size, 0 ); // all slots intialized to zero
    
  //  int inside_vector_size = static_cast<int>(matrix[0].size()); // all will be equal
    
   // auto it_matrix = matrix[0].begin(); // first vector's first slot
   
    
    
    for (int i = 0; i < m_size ; i++) { // amount of vectors in matrix
        auto it_matrix = matrix[i].begin(); // beginning of whatever vector its on
        auto it_vector = vector.begin();
        for(int j = 0 ; j < v_size; j ++){
            result[i]+= (*it_matrix) * (*it_vector);
            it_vector++;
            it_matrix++;
        }
    }

    return result;
}

int main() {
    int loop = 0;
    int num = 1;
    std::vector<int> test_vector( 50, 0 ); // initialzed to
    std::vector<std::vector<int>> test_matrix;
    // Test case 1
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}}; // a vector of int type vectors
    vector<int> vector = {7, 8, 9}; // regular vector

    std::vector<int> result1 = Index(matrix, vector);
    
    for( int i = 0 ; i < result1.size(); i ++){
        std::cout << result1[i] << '\t';
    }
    
    cout << endl;
    
    std::vector<int> result2 = Iterator(matrix, vector);
   
    for( int i = 0 ; i < result1.size(); i ++){
        std::cout << result1[i] << '\t';
    }
    
    std::cout << endl;

    
 
    // 50 coloumn
    while (loop < 50 ){
        
        test_vector[loop] = num;
        
        num++;
        loop++;
    }
    

    
    for (int i =0; i < 100 ; i ++){ // rows
        std::vector<int> v(50);
            for (int k = 0 ; k < 50 ; k ++){ // filling individull vector
                v[k] = num;
                num++;
            }
        test_matrix.push_back(v);
    }
    
    std::vector<int> result4 = Index(test_matrix, test_vector);
    
    for( int i = 0 ; i < result4.size(); i ++){
        std::cout << result4[i] << '\t';
    }
    cout << endl;
    cout << endl;
    cout << endl;
    
    std::vector<int> result5 = Iterator(test_matrix, test_vector);
    
    for( int i = 0 ; i < result5.size(); i ++){
        std::cout << result5[i] << '\t';
    }
    cout << endl;
    auto start = std::chrono::high_resolution_clock::now(); // representing the current value of the clock, returns a std::chrono::time_point representing the current value of the clock
    for (int i =0; i <10000; i ++){
        Index(test_matrix, test_vector);
        
    }
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

       cout << "Time taken (Index): " << duration.count() << " milliseconds" << endl;

    
     start = std::chrono::high_resolution_clock::now(); // representing the current value of the clock, returns a std::chrono::time_point representing the current value of the clock
    for (int i =0; i <10000; i ++){
        Iterator(test_matrix, test_vector);
        
    }
     end = std::chrono::high_resolution_clock::now();
     duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    cout << "Time taken (Iterator): " << duration.count() << " milliseconds" << endl;
    //cout<<"I didn't think I'd get these results I figured the indexing would be quicker ";
    return 0;
}
 
