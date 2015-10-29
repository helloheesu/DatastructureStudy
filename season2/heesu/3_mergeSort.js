function mergeSort(array, startIdx, endIdx) {
  if(startIdx >= endIdx) {
    return;
  }
  var divideIdx = startIdx + ~~((endIdx-startIdx)/2);
  mergeSort(array, startIdx, divideIdx);
  mergeSort(array, divideIdx +1, endIdx);
  return merge(array, startIdx, divideIdx, divideIdx +1, endIdx);
}

function merge(array, aStart, aEnd, bStart, bEnd) { // bStart = aEnd + 1
  var result = [], aIdx = aStart, bIdx = bStart;
  while(aIdx <= aEnd || bIdx <= bEnd) {
    if (bIdx <= bEnd && (aIdx >= aEnd || array[aIdx] >= array[bIdx])) {
      result.push(array[bIdx]);
      bIdx++;
    } else {
      result.push(array[aIdx]);
      aIdx++;
    }
  }
  spliceArray(array, aStart, bEnd+1, result);
}

function spliceArray(originalArray, start, end, replaceArray) {
  for (var i = 0; i < end-start; i++) {
    originalArray[i + start] = replaceArray[i];
  }
}