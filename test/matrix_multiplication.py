mat1 = [
    5, 7, 9, 10,
    2, 3, 2, 8,
    8, 11, 2, 3,
    3,3, 4, 8,
]

mat2 = [
        3, 10, 12, 18,
        12, 1, 4, 9,
        9, 10, 12, 2,
        3, 12, 4, 10,
]

MAT_SIZE = 16

result = [0] * MAT_SIZE

# for i in range(0, 16, 4):
#     for j in range(0, 4):
#         result[i+j] = mat1[i] * mat2[j] + mat1[i+1] * mat2[4+j] + mat1[i+2] * mat2[8+j] + mat1[i+3] * mat2[12+j]

result = [
    mat1[0] * mat2[0] + mat1[1] * mat2[4] + mat1[2] * mat2[8] + mat1[3] * mat2[12],
    mat1[0] * mat2[1] + mat1[1] * mat2[5] + mat1[2] * mat2[9] + mat1[3] * mat2[13],
    mat1[0] * mat2[2] + mat1[1] * mat2[6] + mat1[2] * mat2[10] + mat1[3] * mat2[14],
    mat1[0] * mat2[3] + mat1[1] * mat2[7] + mat1[2] * mat2[11] + mat1[3] * mat2[15],

    mat1[4] * mat2[0] + mat1[5] * mat2[4] + mat1[6] * mat2[8] + mat1[7] * mat2[12],
    mat1[4] * mat2[1] + mat1[5] * mat2[5] + mat1[6] * mat2[9] + mat1[7] * mat2[13],
    mat1[4] * mat2[2] + mat1[5] * mat2[6] + mat1[6] * mat2[10] + mat1[7] * mat2[14],
    mat1[4] * mat2[3] + mat1[5] * mat2[7] + mat1[6] * mat2[11] + mat1[7 ] * mat2[15],

    mat1[8] * mat2[0] + mat1[9] * mat2[4] + mat1[10] * mat2[8] + mat1[11] * mat2[12],
    mat1[8] * mat2[1] + mat1[9] * mat2[5] + mat1[10] * mat2[9] + mat1[11] * mat2[13],
    mat1[8] * mat2[2] + mat1[9] * mat2[6] + mat1[10] * mat2[10] + mat1[11] * mat2[14],
    mat1[8] * mat2[3] + mat1[9] * mat2[7] + mat1[10] * mat2[11] + mat1[11] * mat2[15],

    mat1[12] * mat2[0] + mat1[13] * mat2[4] + mat1[14] * mat2[8] + mat1[15] * mat2[12],
    mat1[12] * mat2[1] + mat1[13] * mat2[5] + mat1[14] * mat2[9] + mat1[15] * mat2[13],
    mat1[12] * mat2[2] + mat1[13] * mat2[6] + mat1[14] * mat2[10] + mat1[15] * mat2[14],
    mat1[12] * mat2[3] + mat1[13] * mat2[7] + mat1[14] * mat2[11] + mat1[15] * mat2[15],
]


print('mat1:')
for i in range(4):
    print(mat1[i*4], mat1[i*4+1], mat1[i*4+2], mat1[i*4+3])

print('\nmat2:')
for i in range(4):
    print(mat2[i*4], mat2[i*4+1], mat2[i*4+2], mat2[i*4+3])

print('\nResult:')
for i in range(4):
    print(result[i*4], result[i*4+1], result[i*4+2], result[i*4+3])