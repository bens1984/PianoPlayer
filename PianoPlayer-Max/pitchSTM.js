// model of a short-term memory suitable for musical sequence processing
//  inputs cause nodes to be activated
//  2nd input is the attention level to add to the node

inlets = 2;

var classes = 12;

var decayRate = 0.9;
var activation = 1.0;   // how much a node is stimulated when an input is received
var minimumActivation = 0;

if (jsarguments.length > 1)
{
    decayRate = jsarguments[1];
}
if (jsarguments.length > 2)
{
    minimumActivation = jsarguments[2];
}
if (jsarguments.length > 3)
    activation = jsarguments[3];

var pitches = new Array(classes);
for (var i = 0; i < classes; i++)
    pitches[i] = 0.0;

function msg_int(a)
{
    a = a % classes;
    for (var i = 0; i < classes; i++)
        pitches[i] *= decayRate;

    pitches[a] += activation;
    if (pitches[a] < minimumActivation)
        pitches[a] = minimumActivation;
//    rescale();
    outlet(0, pitches);
}

function msg_float(a)
{
    if (inlet == 1)    // left most is 0
        activation = a;
    else
        msg_int(a * 1);
}

function rescale()  // adjust the vector so that the max is 1
{
    var max = 0;
    for (var i = 0; i < classes; i++)
        max = (max > pitches[i] ? max : pitches[i]);
    if (max > 1.0)  // don't scale up, only down
    {
        var scale = 1.0 / max;
        for (i = 0; i < classes; i++)
            pitches[i] *= scale;
    }
}


function reset()
{
    for (var i = 0; i < classes; i++)
        pitches[i] = 0.0;
}