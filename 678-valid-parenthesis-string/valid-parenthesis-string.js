/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {  
    let low = 0; // min number of "(" open
    let high = 0; // max number of "(" open

    for (let i = 0; i < s.length; i++) {
        const char = s[i];

        if (char === '(') {
            low++;
            high++;
        } else if (char === ')') {
            low--;
            high--;
        } else if (char === '*') {
            low--; // if * -> (
            high++; // if * -> )
        }

        // ')' - too much and high < 0
        if (high < 0) {
            return false;
        }

        // if low < 0 --> reset it
        low = Math.max(low, 0);
    }

    return low === 0;
};