function countNodes (root) {
  var count = 0;
  var stack = [];
  if (!root || !root.val) {
  	return 0;
  }
  stack.push(root);
  var currentNode;
  while (stack.length > 0) {
  	count++;
  	currentNode = stack.pop();
  	if (currentNode.left) stack.push(currentNode.left);
  	if (currentNode.right) stack.push(currentNode.right);
  }
  return count;
}

var root = {
	val:null
};
countNodes(root);


var node1 = {val:1}, 
node2 = {val:2},
node3 = {val:3},
node4 = {val:4},
node5 = {val:5},
node6 = {val:6},
node7 = {val:7},
node8 = {val:8},
node9 = {val:9},
node10 = {val:10};

node1.left = node2;
node1.right = node3;
node2.left = node4;
node2.right = node5;
node3.left = node6;
node3.right = node7;
node5.left = node8;
node6.right = node9;
node7.left = node10;

var root = node1;

countNodes(root);


function countInternalNodes (root) {
	var count = 0;
	var stack = [];
	stack.push(root);
	var currentNode;
	while (stack.length > 0) {
		currentNode = stack.pop();
		if (!currentNode || (!currentNode.left && !currentNode.right)) {
			continue;
		}
		count++;
		stack.push(currentNode.left, currentNode.right);
	}
	return count;
}
countInternalNodes(root);




function sortLast (array) {
	for (var i = array.length - 1; i > 0; i--) {
		if (array[i] < array[i-1]) {
			var temp = array[i];
			array[i] = array[i-1];
			array[i-1] = temp;
		} else {break;}
	};
	return array;
}

var t = [1,7,9,10,20,30,8];
console.log(t, sortLast(t));

function sortLast (array) {
	var resultIndex = array.length - 1;
	var insertElement = array[resultIndex];

	var prePosOfNum = resultIndex-1;
	while (array[resultIndex] < array[prePosOfNum]) {
		array[prePosOfNum+1] = array[prePosOfNum];
		prePosOfNum++;
	}
	array[prePosOfNum] = insertElement
	return array;
}