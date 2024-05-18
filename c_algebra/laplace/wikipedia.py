def determinant(M):
    # Base case of recursive function: 1x1 matrix
    if len(M) == 1: 
        return M[0][0]

    total = 0
    for column, element in enumerate(M[0]):
        # Exclude first row and current column.
        K = [x[:column] + x[column + 1 :] for x in M[1:]]
        s = 1 if column % 2 == 0 else -1 
        total += s * element * determinant(K)
 
    return total


M = [
    [8,6,4,4,1,7,4,1,9],
    [8,6,3,3,5,4,5,2,9],
    [8,2,4,7,3,6,4,4,9],
    [2,6,7,4,7,3,2,6,2],
    [1,1,5,9,3,6,1,1,9],
    [6,6,2,3,6,2,9,9,1],
    [2,6,4,4,5,8,4,3,6],
    [8,3,9,7,6,6,6,1,9],
    [7,6,8,4,2,4,3,8,2]
    ]

print(determinant(M))

