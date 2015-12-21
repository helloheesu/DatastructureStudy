function countSort (A, k) {
	var count = [];
	for (var i = 0; i < k+1; i++) {
		count.push(0);
	}
	// debugger;
	for (var i = 0; i < A.length; i++) {
		count[A[i]]++;
	}
	for (var i = 1; i < count.length; i++) {
		count[i] += count[i-1];
	}
	// debugger;
	var result = [];
	for (var i = A.length - 1; i >= 0; i--) {
		result[count[A[i]]-1] = A[i];
		count[A[i]] -= 1;
	}
	return result;
}

var test = [2,5,3,0,2,3,0,3];
console.log(countSort(test, 5));