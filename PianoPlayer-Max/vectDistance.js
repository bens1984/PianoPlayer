var prevList = Array(25);

function list(a)
{
var a = arrayfromargs(arguments);
var dist = 0;
for (i = 0; i < a.length; i++)
{
    if (a[i] > prevList[i])
        dist += Math.pow(a[i] - prevList[i], 2);
}
//dist = Math.sqrt(dist);
prevList = a;
 outlet(0, dist);   
}