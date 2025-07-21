var ladderLength = function(beginWord, endWord, wordList) 
{
    let wordSet = new Set(wordList);
    
    if (!wordSet.has(endWord))
    {
        return 0;
    }
    
    let queue = [[beginWord, 1]];
    
    while (queue.length > 0) 
    {
        let [currentWord, steps] = queue.shift();
        
        for (let i = 0; i < currentWord.length; i++) 
        {
            for (let charCode = 97; charCode <= 122; charCode++) 
            {
                let newWord = currentWord.substring(0, i) + String.fromCharCode(charCode) + currentWord.substring(i + 1);
                
                if (newWord === endWord) 
                {
                    return steps + 1;
                }
                
                if (wordSet.has(newWord)) 
                {
                    queue.push([newWord, steps + 1]);
                    wordSet.delete(newWord);
                }
            }
        }
    }
    
    return 0;
};