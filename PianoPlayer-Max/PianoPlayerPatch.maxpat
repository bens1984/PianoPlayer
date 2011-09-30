{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 158.0, 93.0, 1751.0, 856.0 ],
		"bglocked" : 0,
		"defrect" : [ 158.0, 93.0, 1751.0, 856.0 ],
		"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
		"openinpresentation" : 0,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 0,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 0,
		"toolbarvisible" : 1,
		"boxanimatetime" : 200,
		"imprint" : 0,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"boxes" : [ 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "then compare to how learning residual!!!",
					"linecount" : 2,
					"presentation_rect" : [ 1433.0, 310.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1433.0, 310.0, 150.0, 34.0 ],
					"id" : "obj-73",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "looking for indication of novelty. high values indicate expected, low values=unexpected/new",
					"linecount" : 4,
					"fontname" : "Arial",
					"patching_rect" : [ 1274.0, 297.0, 150.0, 62.0 ],
					"id" : "obj-72",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 954.0, 502.0, 50.0, 20.0 ],
					"id" : "obj-70",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "multislider",
					"outlettype" : [ "", "" ],
					"setstyle" : 3,
					"presentation_rect" : [ 943.0, 616.0, 0.0, 0.0 ],
					"patching_rect" : [ 943.0, 616.0, 212.0, 149.0 ],
					"id" : "obj-68",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "- 0.",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1000.0, 552.0, 32.5, 20.0 ],
					"id" : "obj-67",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* 0.5",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1030.0, 519.0, 35.0, 20.0 ],
					"id" : "obj-66",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "+ 0.",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1023.0, 494.0, 32.5, 20.0 ],
					"id" : "obj-65",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* 0.5",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1023.0, 463.0, 35.0, 20.0 ],
					"id" : "obj-64",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "multislider",
					"outlettype" : [ "", "" ],
					"setstyle" : 3,
					"presentation_rect" : [ 1141.0, 453.0, 0.0, 0.0 ],
					"setminmax" : [ 0.0, 1.0 ],
					"patching_rect" : [ 1141.0, 453.0, 212.0, 149.0 ],
					"id" : "obj-63",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1221.0, 417.0, 50.0, 20.0 ],
					"id" : "obj-62",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p scale",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1218.0, 390.0, 49.0, 20.0 ],
					"id" : "obj-60",
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 25.0, 69.0, 640.0, 480.0 ],
						"bglocked" : 0,
						"defrect" : [ 25.0, 69.0, 640.0, 480.0 ],
						"openrect" : [ 0.0, 0.0, 0.0, 0.0 ],
						"openinpresentation" : 0,
						"default_fontsize" : 12.0,
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"gridonopen" : 0,
						"gridsize" : [ 15.0, 15.0 ],
						"gridsnaponopen" : 0,
						"toolbarvisible" : 1,
						"boxanimatetime" : 200,
						"imprint" : 0,
						"enablehscroll" : 1,
						"enablevscroll" : 1,
						"devicewidth" : 0.0,
						"visible" : 1,
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "loadbang",
									"outlettype" : [ "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 394.0, 92.0, 60.0, 20.0 ],
									"id" : "obj-17",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "-100.",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 405.0, 140.0, 38.0, 18.0 ],
									"id" : "obj-16",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "100.",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 352.0, 125.0, 34.0, 18.0 ],
									"id" : "obj-14",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 110.0, 291.0, 25.0, 25.0 ],
									"id" : "obj-12",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "0 will only occur the first time",
									"linecount" : 2,
									"fontname" : "Arial",
									"patching_rect" : [ 180.0, 88.0, 150.0, 34.0 ],
									"id" : "obj-11",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "sel 0.",
									"outlettype" : [ "bang", "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 135.0, 91.0, 39.0, 20.0 ],
									"id" : "obj-9",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "scale 0. 1. 0. 1.",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 110.0, 250.0, 92.0, 20.0 ],
									"id" : "obj-8",
									"numinlets" : 6,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "f",
									"outlettype" : [ "float" ],
									"presentation_rect" : [ 231.0, 192.0, 0.0, 0.0 ],
									"fontname" : "Arial",
									"patching_rect" : [ 231.0, 192.0, 32.5, 20.0 ],
									"id" : "obj-7",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "f",
									"outlettype" : [ "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 136.0, 193.0, 32.5, 20.0 ],
									"id" : "obj-6",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "maximum -100.",
									"outlettype" : [ "float", "int" ],
									"fontname" : "Arial",
									"patching_rect" : [ 231.0, 161.0, 93.0, 20.0 ],
									"id" : "obj-3",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "minimum 100.",
									"outlettype" : [ "float", "int" ],
									"fontname" : "Arial",
									"patching_rect" : [ 136.0, 161.0, 86.0, 20.0 ],
									"id" : "obj-2",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 109.0, 46.0, 25.0, 25.0 ],
									"id" : "obj-1",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-16", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-17", 0 ],
									"destination" : [ "obj-14", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-16", 0 ],
									"destination" : [ "obj-3", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-14", 0 ],
									"destination" : [ "obj-2", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-8", 0 ],
									"destination" : [ "obj-12", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-9", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 1 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-9", 1 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-8", 2 ],
									"hidden" : 0,
									"midpoints" : [ 240.5, 236.5, 148.699997, 236.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-8", 1 ],
									"hidden" : 0,
									"midpoints" : [ 145.5, 231.0, 134.100006, 231.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-7", 0 ],
									"destination" : [ "obj-3", 1 ],
									"hidden" : 0,
									"midpoints" : [ 240.5, 222.0, 329.0, 222.0, 329.0, 151.0, 314.5, 151.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-7", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-6", 0 ],
									"destination" : [ "obj-2", 1 ],
									"hidden" : 0,
									"midpoints" : [ 145.5, 221.0, 224.0, 221.0, 224.0, 155.0, 212.5, 155.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-6", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
 ]
					}
,
					"saved_object_attributes" : 					{
						"default_fontface" : 0,
						"default_fontname" : "Arial",
						"fontname" : "Arial",
						"default_fontsize" : 12.0,
						"globalpatchername" : "",
						"fontface" : 0,
						"fontsize" : 12.0
					}

				}

			}
, 			{
				"box" : 				{
					"maxclass" : "multislider",
					"outlettype" : [ "", "" ],
					"size" : 146,
					"setstyle" : 1,
					"presentation_rect" : [ 423.0, 632.0, 0.0, 0.0 ],
					"setminmax" : [ 0.0, 1.0 ],
					"patching_rect" : [ 423.0, 632.0, 435.0, 152.0 ],
					"id" : "obj-58",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"outlettype" : [ "int", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 139.0, 580.0, 50.0, 20.0 ],
					"id" : "obj-54",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "multislider",
					"outlettype" : [ "", "" ],
					"setstyle" : 3,
					"presentation_rect" : [ 523.0, 652.0, 0.0, 0.0 ],
					"setminmax" : [ 0.0, 1.0 ],
					"patching_rect" : [ 203.0, 633.0, 212.0, 149.0 ],
					"id" : "obj-25",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"presentation_rect" : [ 523.0, 619.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 203.0, 600.0, 50.0, 20.0 ],
					"id" : "obj-34",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "zl sum",
					"outlettype" : [ "", "" ],
					"presentation_rect" : [ 523.0, 592.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 203.0, 573.0, 45.0, 20.0 ],
					"id" : "obj-36",
					"numinlets" : 2,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "mxj fuzzyArt 12 0. 0.2 0.7",
					"outlettype" : [ "", "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 139.0, 544.0, 146.0, 20.0 ],
					"id" : "obj-38",
					"numinlets" : 1,
					"numoutlets" : 3,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "reset",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1066.0, 236.0, 37.0, 18.0 ],
					"id" : "obj-18",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "multislider",
					"outlettype" : [ "", "" ],
					"setstyle" : 3,
					"presentation_rect" : [ 1403.0, 441.0, 0.0, 0.0 ],
					"setminmax" : [ 0.0, 1.0 ],
					"patching_rect" : [ 1403.0, 441.0, 212.0, 149.0 ],
					"id" : "obj-8",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"presentation_rect" : [ 1419.0, 324.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1403.0, 408.0, 50.0, 20.0 ],
					"id" : "obj-5",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "zl sum",
					"outlettype" : [ "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1403.0, 381.0, 45.0, 20.0 ],
					"id" : "obj-3",
					"numinlets" : 2,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "multislider",
					"outlettype" : [ "", "" ],
					"size" : 63,
					"setstyle" : 1,
					"presentation_rect" : [ 929.0, 630.0, 0.0, 0.0 ],
					"setminmax" : [ 0.0, 1.0 ],
					"patching_rect" : [ 1361.0, 619.0, 435.0, 152.0 ],
					"id" : "obj-1",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1083.0, 400.0, 50.0, 20.0 ],
					"id" : "obj-59",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "viewsource",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1068.0, 295.0, 71.0, 18.0 ],
					"id" : "obj-57",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"outlettype" : [ "int", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 979.0, 380.0, 50.0, 20.0 ],
					"id" : "obj-55",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "js vecMag.js 0",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1083.0, 362.0, 87.0, 20.0 ],
					"id" : "obj-53",
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "mxj fuzzyArt 7 0. 0.2 0.85",
					"outlettype" : [ "", "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1019.0, 333.0, 146.0, 20.0 ],
					"id" : "obj-52",
					"numinlets" : 1,
					"numoutlets" : 3,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 914.0, 299.0, 50.0, 20.0 ],
					"id" : "obj-51",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 730.0, 289.0, 50.0, 20.0 ],
					"id" : "obj-50",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "scale -1. 1. 0. 1.",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 914.0, 271.0, 96.0, 20.0 ],
					"id" : "obj-48",
					"numinlets" : 6,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t f f",
					"outlettype" : [ "float", "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 914.0, 216.0, 32.5, 20.0 ],
					"id" : "obj-47",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "- 0.",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 914.0, 244.0, 32.5, 20.0 ],
					"id" : "obj-46",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "abs",
					"outlettype" : [ "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 520.0, 156.0, 30.0, 20.0 ],
					"id" : "obj-45",
					"numinlets" : 1,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "zl join 20",
					"outlettype" : [ "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 575.0, 479.0, 58.0, 20.0 ],
					"id" : "obj-44",
					"numinlets" : 2,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "scale 0. 48. 0. 1.",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 730.0, 261.0, 99.0, 20.0 ],
					"id" : "obj-43",
					"numinlets" : 6,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "+ 48.",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 132.0, 296.0, 38.0, 20.0 ],
					"id" : "obj-42",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "split 0. 128.",
					"outlettype" : [ "float", "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 113.0, 268.0, 72.0, 20.0 ],
					"id" : "obj-41",
					"numinlets" : 3,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 40.0, 358.0, 50.0, 20.0 ],
					"id" : "obj-40",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 42.0, 333.0, 50.0, 20.0 ],
					"id" : "obj-39",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "button",
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 37.0, 192.0, 20.0, 20.0 ],
					"id" : "obj-37",
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"outlettype" : [ "int", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 520.0, 234.0, 50.0, 20.0 ],
					"id" : "obj-35",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "!- 12",
					"outlettype" : [ "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 553.0, 209.0, 35.0, 20.0 ],
					"id" : "obj-33",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "split 0 6",
					"outlettype" : [ "int", "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 520.0, 183.0, 52.0, 20.0 ],
					"id" : "obj-32",
					"numinlets" : 3,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "% 12",
					"outlettype" : [ "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 520.0, 122.0, 38.0, 20.0 ],
					"id" : "obj-31",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "multislider",
					"outlettype" : [ "", "" ],
					"size" : 7,
					"setminmax" : [ 0.0, 1.0 ],
					"patching_rect" : [ 631.0, 319.0, 261.0, 132.0 ],
					"id" : "obj-30",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "js linearSTM.js 0.15 7",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 520.0, 259.0, 126.0, 20.0 ],
					"id" : "obj-29",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "t i i",
					"outlettype" : [ "int", "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 520.0, 70.0, 32.5, 20.0 ],
					"id" : "obj-28",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "-",
					"outlettype" : [ "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 520.0, 97.0, 32.5, 20.0 ],
					"id" : "obj-27",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "i",
					"outlettype" : [ "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 359.0, 237.0, 32.5, 20.0 ],
					"id" : "obj-26",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 44.0, 263.0, 50.0, 20.0 ],
					"id" : "obj-24",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "multislider",
					"outlettype" : [ "", "" ],
					"size" : 12,
					"setminmax" : [ 0.0, 1.0 ],
					"patching_rect" : [ 359.0, 320.0, 261.0, 132.0 ],
					"id" : "obj-23",
					"numinlets" : 1,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "js linearSTM.js 0.15",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 359.0, 265.0, 116.0, 20.0 ],
					"id" : "obj-22",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "noteout",
					"fontname" : "Arial",
					"patching_rect" : [ 112.0, 401.0, 51.0, 20.0 ],
					"id" : "obj-21",
					"numinlets" : 3,
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "makenote 96 400",
					"outlettype" : [ "float", "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 112.0, 374.0, 103.0, 20.0 ],
					"id" : "obj-20",
					"numinlets" : 3,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 185.0, 155.0, 50.0, 20.0 ],
					"id" : "obj-19",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "toggle",
					"outlettype" : [ "int" ],
					"patching_rect" : [ 78.0, 161.0, 20.0, 20.0 ],
					"id" : "obj-17",
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "+ 40.",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 112.0, 351.0, 38.0, 20.0 ],
					"id" : "obj-15",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "% 48.",
					"outlettype" : [ "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 112.0, 326.0, 41.0, 20.0 ],
					"id" : "obj-14",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "+ 0.",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 113.0, 245.0, 32.5, 20.0 ],
					"id" : "obj-12",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "f",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 78.0, 220.0, 32.5, 20.0 ],
					"id" : "obj-11",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* 4.",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 173.0, 125.0, 32.5, 20.0 ],
					"id" : "obj-10",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "metro 100",
					"outlettype" : [ "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 78.0, 190.0, 65.0, 20.0 ],
					"id" : "obj-9",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "scale 0. 1. -1. 1.",
					"outlettype" : [ "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 173.0, 100.0, 96.0, 20.0 ],
					"id" : "obj-7",
					"numinlets" : 6,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "lever position",
					"fontname" : "Arial",
					"patching_rect" : [ 238.0, 75.0, 150.0, 20.0 ],
					"id" : "obj-6",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"minimum" : 0.0,
					"maximum" : 1.0,
					"fontname" : "Arial",
					"patching_rect" : [ 173.0, 70.0, 50.0, 20.0 ],
					"id" : "obj-4",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Lever Piano Player",
					"fontname" : "Arial",
					"patching_rect" : [ 229.0, 25.0, 150.0, 20.0 ],
					"id" : "obj-2",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-70", 0 ],
					"destination" : [ "obj-67", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-62", 0 ],
					"destination" : [ "obj-70", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1230.5, 469.0, 963.5, 469.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-65", 0 ],
					"destination" : [ "obj-66", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-66", 0 ],
					"destination" : [ "obj-65", 1 ],
					"hidden" : 0,
					"midpoints" : [ 1039.5, 547.0, 1079.0, 547.0, 1079.0, 486.0, 1046.0, 486.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-64", 0 ],
					"destination" : [ "obj-65", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-62", 0 ],
					"destination" : [ "obj-64", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-67", 0 ],
					"destination" : [ "obj-68", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-62", 0 ],
					"destination" : [ "obj-67", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1230.5, 443.0, 1009.5, 443.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-60", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-62", 0 ],
					"destination" : [ "obj-63", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-60", 0 ],
					"destination" : [ "obj-62", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 1 ],
					"destination" : [ "obj-58", 0 ],
					"hidden" : 0,
					"midpoints" : [ 212.0, 570.5, 432.5, 570.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 0 ],
					"destination" : [ "obj-54", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 1 ],
					"destination" : [ "obj-36", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-36", 0 ],
					"destination" : [ "obj-34", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-34", 0 ],
					"destination" : [ "obj-25", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 0 ],
					"destination" : [ "obj-55", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-52", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-57", 0 ],
					"destination" : [ "obj-52", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 1 ],
					"destination" : [ "obj-1", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1092.0, 359.0, 1370.5, 359.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 1 ],
					"destination" : [ "obj-53", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 1 ],
					"destination" : [ "obj-3", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-18", 0 ],
					"destination" : [ "obj-52", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-17", 0 ],
					"destination" : [ "obj-9", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-5", 0 ],
					"destination" : [ "obj-8", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-3", 0 ],
					"destination" : [ "obj-5", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-53", 0 ],
					"destination" : [ "obj-59", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-4", 0 ],
					"destination" : [ "obj-7", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-7", 0 ],
					"destination" : [ "obj-10", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-19", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 0 ],
					"destination" : [ "obj-21", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-20", 1 ],
					"destination" : [ "obj-21", 1 ],
					"hidden" : 0,
					"midpoints" : [ 205.5, 397.0, 137.5, 397.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-22", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-10", 0 ],
					"destination" : [ "obj-12", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-12", 0 ],
					"hidden" : 0,
					"midpoints" : [ 87.5, 241.5, 122.5, 241.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-11", 0 ],
					"destination" : [ "obj-24", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-22", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 0 ],
					"destination" : [ "obj-27", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-28", 1 ],
					"destination" : [ "obj-27", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-26", 0 ],
					"destination" : [ "obj-28", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-27", 0 ],
					"destination" : [ "obj-31", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 1 ],
					"destination" : [ "obj-33", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-33", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-32", 0 ],
					"destination" : [ "obj-35", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-11", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-26", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-20", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-40", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 1 ],
					"destination" : [ "obj-42", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-12", 0 ],
					"destination" : [ "obj-41", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-41", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-42", 0 ],
					"destination" : [ "obj-14", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-11", 1 ],
					"hidden" : 0,
					"midpoints" : [ 121.5, 347.0, 158.0, 347.0, 158.0, 218.0, 101.0, 218.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-39", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-15", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-43", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-35", 0 ],
					"destination" : [ "obj-29", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-29", 0 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-31", 0 ],
					"destination" : [ "obj-45", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-45", 0 ],
					"destination" : [ "obj-32", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-47", 0 ],
					"destination" : [ "obj-46", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-47", 1 ],
					"destination" : [ "obj-46", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 0 ],
					"destination" : [ "obj-47", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-46", 0 ],
					"destination" : [ "obj-48", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-43", 0 ],
					"destination" : [ "obj-50", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-48", 0 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
 ]
	}

}
