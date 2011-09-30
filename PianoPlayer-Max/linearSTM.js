inlets = 2;

var classes = 12;

var decayRate = 0.1;
var activation = 1.0;

if (jsarguments.length > 1)
{
    decayRate = jsarguments[1];
}
if (jsarguments.length > 2)
    classes = jsarguments[2];
if (jsarguments.length > 3)
    activation = jsarguments[3];

var pitches = new Array(classes);
for (var i = 0; i < classes; i++)
    pitches[i] = 0.0;

function msg_int(a)
{
    a = a % classes;
    for (var i = 0; i < classes; i++)
    {
        pitches[i] -= decayRate;
        if (pitches[i] < 0)
            pitches[i] = 0;
    }

    pitches[a] += activation;
    if (pitches[a] > 1.0)
        pitches[a] = 1.0;
    outlet(0, pitches);
}
function msg_float(a)
{
    activation = a;
}

function reset()
{
var pitches = new Array(classes);
for (var i = 0; i < classes; i++)
    pitches[i] = 0.0;
}