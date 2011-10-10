// take a list and calculate the magnitude of the elements as if it is an n-vector

var normalize = 0;

if (jsarguments.length>1)
    normalize = jsarguments[1];

function list(a)
{
var a = arrayfromargs(arguments);
var magnitude = 0;
if (normalize == 1)
{
    var total = 0;
    for (i = 0; i < a.length; i++)
        total += a[i];
    for (i = 0; i < a.length; i++)
        a[i] /= total;
}
for (i = 0; i < a.length; i++)
{
        magnitude += Math.pow(a[i], 2);
}
magnitude = Math.sqrt(magnitude);
outlet(0, magnitude);   
}