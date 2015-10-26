function insertionSort (array) {
	if (array.length <= 1) {
		return array;
	}
	for (var i = 1; i < array.length; i++) {
		var currentElement = array[i];
		for (var prePos = i-1; prePos >= 0 && array[prePos] > currentElement; prePos--) {
			array[prePos+1] = array[prePos];
		}
		array[prePos+1] = currentElement;
	}
	return array;
}

var testArray = [5,2,4,6,1,3];
console.log(testArray);
console.log('result',insertionSort(testArray));

var testArray = [1,3,6,2];
console.log(testArray);
console.log('result',insertionSort(testArray));
var testArray = [1,2,3,6];
console.log(testArray);
console.log('result',insertionSort(testArray));
var testArray = [2,3,6,1];
console.log(testArray);
console.log('result',insertionSort(testArray));
var testArray = [6,3,2,1];
console.log(testArray);
console.log('result',insertionSort(testArray));

var testArray = [2];
console.log(testArray);
console.log('result',insertionSort(testArray));
var testArray = [];
console.log(testArray);
console.log('result',insertionSort(testArray));
var testArray = [0];
console.log(testArray);
console.log('result',insertionSort(testArray));
var testArray = [-1,0,4];
console.log(testArray);
console.log('result',insertionSort(testArray));

var testArray = [2,2,2];
console.log(testArray);
console.log('result',insertionSort(testArray));
var testArray = [1,0,0,0,-2];
console.log(testArray);
console.log('result',insertionSort(testArray));

function isSorted (array) {
	for (var i = 0; i< array.length - 1; i++) {
		if (array[i] > array[i+1]) {
			return false;
		}
	}
	return true;
}

var testArray = [5,2,4,6,1,3];
console.log(testArray);
console.log('result',isSorted(testArray));

var testArray = [1,3,6,2];
console.log(testArray);
console.log('result',isSorted(testArray));
var testArray = [1,2,3,6];
console.log(testArray);
console.log('result',isSorted(testArray));
var testArray = [2,3,6,1];
console.log(testArray);
console.log('result',isSorted(testArray));
var testArray = [6,3,2,1];
console.log(testArray);
console.log('result',isSorted(testArray));

var testArray = [2];
console.log(testArray);
console.log('result',isSorted(testArray));
var testArray = [];
console.log(testArray);
console.log('result',isSorted(testArray));
var testArray = [0];
console.log(testArray);
console.log('result',isSorted(testArray));
var testArray = [-1,0,4];
console.log(testArray);
console.log('result',isSorted(testArray));

var testArray = [2,2,2];
console.log(testArray);
console.log('result',isSorted(testArray));
var testArray = [1,0,0,0,-2];
console.log(testArray);
console.log('result',isSorted(testArray));
/* occurs error. should deal with unexpected types.
var testArray = [2, undefined, -1, 4];
console.log(testArray);
console.log('result',isSorted(testArray));
*/
