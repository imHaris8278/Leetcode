/**
 * @param {number[][]} matrix
 * @return {void}
 */
var setZeroes = function(matrix) 
{
    const m = matrix.length;
    const n = matrix[0].length;
    let firstRowHasZero = false;
    let firstColHasZero = false;

    for (let i = 0; i < m; i++) 
    {
        if (matrix[i][0] === 0) 
        {
            firstColHasZero = true;
            break;
        }
    }

    for (let j = 0; j < n; j++) 
    {
        if (matrix[0][j] === 0) 
        {
            firstRowHasZero = true;
            break;
        }
    }

    for (let i = 1; i < m; i++) 
    {
        for (let j = 1; j < n; j++) 
        {
            if (matrix[i][j] === 0) 
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (let i = 1; i < m; i++) 
    {
        for (let j = 1; j < n; j++) 
        {
            if (matrix[i][0] === 0 || matrix[0][j] === 0) 
            {
                matrix[i][j] = 0;
            }
        }
    }

    if (firstRowHasZero) 
    {
        for (let j = 0; j < n; j++) 
        {
            matrix[0][j] = 0;
        }
    }

    if (firstColHasZero) 
    {
        for (let i = 0; i < m; i++) 
        {
            matrix[i][0] = 0;
        }
    }
};

let matrix = [
  [1, 1, 1],
  [1, 0, 1],
  [1, 1, 1]
];

setZeroes(matrix);
console.log(matrix);

matrix = [
  [0, 1, 2, 0],
  [3, 4, 5, 2],
  [1, 3, 1, 5]
];

setZeroes(matrix);
console.log(matrix); 
