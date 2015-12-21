function Graph (directed) {
	this.Vs = {};
	this.lastId = 0; // VertexId starts from 1;
	this.directed = directed || false;
}
function Vertex (value) {
	this.id = undefined;
	this.value = value;
	this.adjacentVids = [];
}
Graph.prototype.insertVertex = function (value) {
	var newV = new Vertex(value);
	newV.id = ++(this.lastId);
	this.Vs[newV.id] = newV;
	return newV.id;
};
Graph.prototype.connectVs = function (sourceVid, destVid) {
	var sV = this.Vs[sourceVid];
	var dV = this.Vs[destVid];
	if (!sV) {
		console.error('invalid sourceVid');
		return;
	}
	if (!dV) {
		console.error('invalid destVid');
		return;
	}

	if (sV.adjacentVids.indexOf(destVid) < 0) {
		sV.adjacentVids.push(destVid);
	}
	if (!this.directed && dV.adjacentVids.indexOf(sourceVid) < 0) {
		dV.adjacentVids.push(sourceVid);
	}
};
Graph.prototype.disconnectVs = function (sourceVid, destVid) {
	// not this time.
};

function BFS (G, sourceVid) {
	var vertices = G.Vs;
	if (!G || !vertices) {
		console.error('invalid graph');
		return;
	}
	var s = vertices[sourceVid];
	if (!s) {
		console.error('invalid sourceVid');
		return;
	}

	// initialization
	for (var i in vertices) {
		vertices[i].predecessorId = undefined;
	}
	var verticesToVisit = new Queue();
	verticesToVisit.enqueue(s);
	while (!verticesToVisit.isEmpty()) {
		var currentV = verticesToVisit.dequeue();
		for (var i = currentV.adjacentVids.length - 1; i >= 0; i--) {
			var childV = vertices[currentV.adjacentVids[i]];
			if (childV == s || childV.predecessorId) {
				continue;
			}
			childV.predecessorId = currentV.id;
			verticesToVisit.enqueue(childV);
		}
	}
}

function printPath (G, sourceVid, destVid) {
	var predecessorId = G.Vs[destVid].predecessorId;
	if (destVid == sourceVid) {
		console.log(destVid);
	} else if (!predecessorId) {
		console.log("no path from "+sourceVid+" from "+destVid);
	} else {
		printPath(G, sourceVid, predecessorId);
		console.log(destVid);
	}
}


var tttt = new Graph(false);
tttt.insertVertex('r'); // 1
tttt.insertVertex('s'); // 2
tttt.insertVertex('t'); // 3
tttt.insertVertex('u'); // 4
tttt.insertVertex('v'); // 5
tttt.insertVertex('w'); // 6
tttt.insertVertex('x'); // 7
tttt.insertVertex('y'); // 8
tttt.connectVs(1,2);
tttt.connectVs(1,5);
tttt.connectVs(2,6);
tttt.connectVs(3,4);
tttt.connectVs(3,6);
tttt.connectVs(3,7);
tttt.connectVs(4,7);
tttt.connectVs(4,8);
tttt.connectVs(6,7);
tttt.connectVs(7,8);

BFS(tttt, 2);
printPath(tttt, 2, 4);



/*
Graph : [Vertices]
Vertex : {
	id : n,
	adjacentVs : [Vertices]
}
*/
// 초기화 따로 필요.

/*
function dfsVisit_iterative (G, v) {
	var stack = [v];
	while (stack.length) {
		var currentV = stack.pop();
		console.log(currentV.id);
		currentV.visited = true;
		var adjVs = currentV.adjacentVs;

		for (var i = adjVs.length - 1; i >= 0; i--) {
			var adjV = adjVs[i];
			if (adjV == v || adjV.visited) {
				continue;
			}
			adjV.predecessor = currentV;
			stack.push(adjV);
		}
	}
}

function dfsVisit_recursion (G, v) {
	console.log(v.id);
	v.visited = true;
	var adjVs = v.adjacentVs;
	for (var i = 0; i < adjVs.length; i++) {
		var adjV = adjVs[i];
		if (adjV.visited) {
			continue;
		}
		dfsVisit_recursion(G, adjV);
	}
}
*/