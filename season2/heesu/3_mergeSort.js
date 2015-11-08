function mergeSort(array, startIdx, endIdx) {
  if (!array || !(length in array)) {
    return array;
  }
  if (typeof startIdx == "undefined") startIdx = 0;
  if (typeof endIdx == "undefined") endIdx = array.length-1;
  if (startIdx >= endIdx) {
    return array;
  }

  // `~~number` is shorthand for Math.floor()
  var midIdx = startIdx + ~~((endIdx - startIdx)/2);
  mergeSort(array, startIdx, midIdx);
  mergeSort(array, midIdx+1, endIdx);
  merge(array, startIdx, midIdx, endIdx);

  return array;
}

function merge (array, left, mid, right) {
  var aStart = left, aEnd = mid, bStart = mid+1, bEnd = right;
  var aIdx = aStart, bIdx = bStart;
  var result = [];

  while (aIdx <= aEnd && bIdx <= bEnd) {
    if (array[aIdx] < array[bIdx]) {
      result.push(array[aIdx++]);
    } else {
      result.push(array[bIdx++]);
    }
  }

  while (aIdx <= aEnd) {
    result.push(array[aIdx++]);
  }
  while (bIdx <= bEnd) {
    result.push(array[bIdx++]);
  }

  for (var i = 0; i < result.length; i++) {
    array[left+i] = result[i];
  }
}
