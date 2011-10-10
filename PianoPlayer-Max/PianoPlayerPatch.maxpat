{
	"patcher" : 	{
		"fileversion" : 1,
		"rect" : [ 139.0, 93.0, 1976.0, 1027.0 ],
		"bglocked" : 0,
		"defrect" : [ 139.0, 93.0, 1976.0, 1027.0 ],
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
					"maxclass" : "message",
					"text" : "reset",
					"outlettype" : [ "" ],
					"presentation_rect" : [ 1125.0, 538.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1125.0, 538.0, 37.0, 18.0 ],
					"id" : "obj-148",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p CHARTS",
					"presentation_rect" : [ 1229.0, 644.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1229.0, 644.0, 78.5, 20.0 ],
					"id" : "obj-149",
					"numinlets" : 6,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 1626.0, 612.0, 830.0, 683.0 ],
						"bglocked" : 0,
						"defrect" : [ 1626.0, 612.0, 830.0, 683.0 ],
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
									"text" : "zl iter 1",
									"outlettype" : [ "", "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 540.0, 38.0, 49.0, 20.0 ],
									"id" : "obj-2",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"size" : 16,
									"setstyle" : 1,
									"setminmax" : [ 0.5, 1.0 ],
									"patching_rect" : [ 63.0, 487.0, 388.0, 152.0 ],
									"id" : "obj-123",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "is this a good intrinsic reward measure?",
									"linecount" : 2,
									"fontname" : "Arial",
									"patching_rect" : [ 593.0, 453.0, 150.0, 34.0 ],
									"id" : "obj-84",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 0.1 ],
									"patching_rect" : [ 543.0, 491.0, 212.0, 149.0 ],
									"id" : "obj-78",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "clip 0. 0.3",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 540.0, 63.0, 62.0, 20.0 ],
									"id" : "obj-76",
									"numinlets" : 3,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 0.3 ],
									"patching_rect" : [ 540.0, 85.0, 212.0, 149.0 ],
									"id" : "obj-75",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "amount of learning that is taking place per sample",
									"linecount" : 2,
									"fontname" : "Arial",
									"patching_rect" : [ 603.0, 35.0, 150.0, 34.0 ],
									"id" : "obj-73",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "looking for indication of novelty. high values indicate expected, low values=unexpected/new",
									"linecount" : 4,
									"fontname" : "Arial",
									"patching_rect" : [ 592.0, 233.0, 150.0, 62.0 ],
									"id" : "obj-72",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 84.0, 72.0, 50.0, 20.0 ],
									"id" : "obj-70",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"patching_rect" : [ 78.0, 129.0, 212.0, 149.0 ],
									"id" : "obj-68",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "- 0.",
									"outlettype" : [ "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 128.0, 99.0, 32.5, 20.0 ],
									"id" : "obj-67",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 299.0, 128.0, 212.0, 149.0 ],
									"id" : "obj-63",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 539.0, 297.0, 212.0, 149.0 ],
									"id" : "obj-8",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"size" : 16,
									"setstyle" : 1,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 50.0, 286.0, 435.0, 152.0 ],
									"id" : "obj-1",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-136",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "float" ],
									"patching_rect" : [ 127.5, 38.0, 25.0, 25.0 ],
									"id" : "obj-137",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "float" ],
									"patching_rect" : [ 543.0, 457.0, 25.0, 25.0 ],
									"id" : "obj-138",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 540.0, 8.0, 25.0, 25.0 ],
									"id" : "obj-139",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "float" ],
									"patching_rect" : [ 539.0, 262.0, 25.0, 25.0 ],
									"id" : "obj-140",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 63.0, 454.0, 25.0, 25.0 ],
									"id" : "obj-141",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-76", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-139", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-67", 0 ],
									"destination" : [ "obj-68", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-70", 0 ],
									"destination" : [ "obj-67", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-76", 0 ],
									"destination" : [ "obj-75", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-136", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-137", 0 ],
									"destination" : [ "obj-70", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-137", 0 ],
									"destination" : [ "obj-67", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-137", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-138", 0 ],
									"destination" : [ "obj-78", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-140", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-141", 0 ],
									"destination" : [ "obj-123", 0 ],
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
					"maxclass" : "newobj",
					"text" : "p intrinsicReward",
					"outlettype" : [ "float", "float", "float" ],
					"presentation_rect" : [ 1106.0, 600.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1106.0, 600.0, 104.0, 20.0 ],
					"id" : "obj-150",
					"numinlets" : 2,
					"numoutlets" : 3,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 25.0, 69.0, 542.0, 594.0 ],
						"bglocked" : 0,
						"defrect" : [ 25.0, 69.0, 542.0, 594.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "0.",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 373.0, 482.0, 32.5, 18.0 ],
									"id" : "obj-88",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "residual * inverse novelty",
									"fontname" : "Arial",
									"patching_rect" : [ 368.0, 397.0, 150.0, 20.0 ],
									"id" : "obj-83",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 373.0, 459.0, 20.0, 20.0 ],
									"id" : "obj-81",
									"numinlets" : 1,
									"numoutlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "split 0 0.3",
									"outlettype" : [ "float", "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 330.0, 434.0, 62.0, 20.0 ],
									"id" : "obj-79",
									"numinlets" : 3,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "* 0.",
									"outlettype" : [ "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 330.0, 397.0, 32.5, 20.0 ],
									"id" : "obj-77",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 188.0, 243.0, 50.0, 20.0 ],
									"id" : "obj-62",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p scale",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 188.0, 216.0, 49.0, 20.0 ],
									"id" : "obj-60",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"patcher" : 									{
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
										"boxes" : [ 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"patching_rect" : [ 110.0, 291.0, 25.0, 25.0 ],
													"id" : "obj-12",
													"numinlets" : 1,
													"numoutlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "f",
													"outlettype" : [ "float" ],
													"fontname" : "Arial",
													"patching_rect" : [ 231.0, 192.0, 32.5, 20.0 ],
													"id" : "obj-7",
													"numinlets" : 2,
													"numoutlets" : 1,
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-6", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [ 145.5, 221.0, 224.0, 221.0, 224.0, 155.0, 212.5, 155.0 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-7", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [ 240.5, 222.0, 329.0, 222.0, 329.0, 151.0, 314.5, 151.0 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-8", 1 ],
													"hidden" : 0,
													"midpoints" : [ 145.5, 231.0, 134.100006, 231.0 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-8", 2 ],
													"hidden" : 0,
													"midpoints" : [ 240.5, 236.5, 148.699997, 236.5 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 1 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 1 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-9", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-14", 0 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-16", 0 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-17", 0 ],
													"destination" : [ "obj-14", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-17", 0 ],
													"destination" : [ "obj-16", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
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
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 241.0, 166.0, 50.0, 20.0 ],
									"id" : "obj-5",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl sum",
									"outlettype" : [ "", "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 241.0, 139.0, 45.0, 20.0 ],
									"id" : "obj-3",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 50.0, 138.0, 50.0, 20.0 ],
									"id" : "obj-59",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "js vecMag.js 0",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 50.0, 100.0, 87.0, 20.0 ],
									"id" : "obj-53",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-127",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 343.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-128",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 167.0, 277.0, 25.0, 25.0 ],
									"id" : "obj-129",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 329.5, 516.0, 25.0, 25.0 ],
									"id" : "obj-130",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 241.0, 205.0, 25.0, 25.0 ],
									"id" : "obj-131",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-53", 0 ],
									"destination" : [ "obj-59", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-60", 0 ],
									"destination" : [ "obj-62", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-60", 0 ],
									"hidden" : 0,
									"midpoints" : [ 250.5, 163.0, 197.5, 163.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-62", 0 ],
									"destination" : [ "obj-77", 0 ],
									"hidden" : 0,
									"midpoints" : [ 197.5, 379.5, 339.5, 379.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-77", 0 ],
									"destination" : [ "obj-79", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-79", 1 ],
									"destination" : [ "obj-81", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-53", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-81", 0 ],
									"destination" : [ "obj-88", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-127", 0 ],
									"destination" : [ "obj-53", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-128", 0 ],
									"destination" : [ "obj-77", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-62", 0 ],
									"destination" : [ "obj-129", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-79", 0 ],
									"destination" : [ "obj-130", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-88", 0 ],
									"destination" : [ "obj-130", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-131", 0 ],
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
					"maxclass" : "number",
					"outlettype" : [ "int", "bang" ],
					"presentation_rect" : [ 1052.0, 610.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1052.0, 610.0, 50.0, 20.0 ],
					"id" : "obj-151",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "mxj fuzzyArt 2 0. 0.2 0.83",
					"outlettype" : [ "", "", "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1092.0, 563.0, 146.0, 20.0 ],
					"id" : "obj-152",
					"numinlets" : 1,
					"numoutlets" : 4,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "message",
					"text" : "reset",
					"outlettype" : [ "" ],
					"presentation_rect" : [ 1256.0, 420.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1233.0, 434.0, 37.0, 18.0 ],
					"id" : "obj-147",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p CHARTS",
					"presentation_rect" : [ 1337.0, 540.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1337.0, 540.0, 78.5, 20.0 ],
					"id" : "obj-143",
					"numinlets" : 6,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 802.0, 497.0, 830.0, 683.0 ],
						"bglocked" : 0,
						"defrect" : [ 802.0, 497.0, 830.0, 683.0 ],
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
									"text" : "zl iter 1",
									"outlettype" : [ "", "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 540.0, 30.0, 49.0, 20.0 ],
									"id" : "obj-2",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"size" : 13,
									"setstyle" : 1,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 63.0, 487.0, 388.0, 152.0 ],
									"id" : "obj-123",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "is this a good intrinsic reward measure?",
									"linecount" : 2,
									"fontname" : "Arial",
									"patching_rect" : [ 593.0, 453.0, 150.0, 34.0 ],
									"id" : "obj-84",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 0.1 ],
									"patching_rect" : [ 543.0, 491.0, 212.0, 149.0 ],
									"id" : "obj-78",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "clip 0. 0.3",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 540.0, 52.0, 62.0, 20.0 ],
									"id" : "obj-76",
									"numinlets" : 3,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 0.3 ],
									"patching_rect" : [ 540.0, 74.0, 212.0, 149.0 ],
									"id" : "obj-75",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "amount of learning that is taking place per sample",
									"linecount" : 2,
									"fontname" : "Arial",
									"patching_rect" : [ 603.0, 35.0, 150.0, 34.0 ],
									"id" : "obj-73",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "looking for indication of novelty. high values indicate expected, low values=unexpected/new",
									"linecount" : 4,
									"fontname" : "Arial",
									"patching_rect" : [ 592.0, 233.0, 150.0, 62.0 ],
									"id" : "obj-72",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 84.0, 72.0, 50.0, 20.0 ],
									"id" : "obj-70",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"patching_rect" : [ 78.0, 129.0, 212.0, 149.0 ],
									"id" : "obj-68",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "- 0.",
									"outlettype" : [ "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 128.0, 99.0, 32.5, 20.0 ],
									"id" : "obj-67",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 299.0, 128.0, 212.0, 149.0 ],
									"id" : "obj-63",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 539.0, 297.0, 212.0, 149.0 ],
									"id" : "obj-8",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"size" : 13,
									"setstyle" : 1,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 50.0, 286.0, 435.0, 152.0 ],
									"id" : "obj-1",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-136",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "float" ],
									"patching_rect" : [ 127.5, 38.0, 25.0, 25.0 ],
									"id" : "obj-137",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 543.0, 457.0, 25.0, 25.0 ],
									"id" : "obj-138",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 540.0, 3.0, 25.0, 25.0 ],
									"id" : "obj-139",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "float" ],
									"patching_rect" : [ 539.0, 262.0, 25.0, 25.0 ],
									"id" : "obj-140",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 63.0, 454.0, 25.0, 25.0 ],
									"id" : "obj-141",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-76", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-139", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-141", 0 ],
									"destination" : [ "obj-123", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-140", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-138", 0 ],
									"destination" : [ "obj-78", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-137", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-137", 0 ],
									"destination" : [ "obj-67", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-137", 0 ],
									"destination" : [ "obj-70", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-136", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-76", 0 ],
									"destination" : [ "obj-75", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-70", 0 ],
									"destination" : [ "obj-67", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-67", 0 ],
									"destination" : [ "obj-68", 0 ],
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
					"maxclass" : "newobj",
					"text" : "p intrinsicReward",
					"outlettype" : [ "float", "float", "" ],
					"presentation_rect" : [ 1214.0, 496.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1214.0, 496.0, 104.0, 20.0 ],
					"id" : "obj-144",
					"numinlets" : 2,
					"numoutlets" : 3,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 25.0, 69.0, 542.0, 594.0 ],
						"bglocked" : 0,
						"defrect" : [ 25.0, 69.0, 542.0, 594.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "0.",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 373.0, 482.0, 32.5, 18.0 ],
									"id" : "obj-88",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "residual * inverse novelty",
									"fontname" : "Arial",
									"patching_rect" : [ 368.0, 397.0, 150.0, 20.0 ],
									"id" : "obj-83",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 373.0, 459.0, 20.0, 20.0 ],
									"id" : "obj-81",
									"numinlets" : 1,
									"numoutlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "split 0 0.3",
									"outlettype" : [ "float", "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 330.0, 434.0, 62.0, 20.0 ],
									"id" : "obj-79",
									"numinlets" : 3,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "* 0.",
									"outlettype" : [ "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 330.0, 397.0, 32.5, 20.0 ],
									"id" : "obj-77",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 188.0, 243.0, 50.0, 20.0 ],
									"id" : "obj-62",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p scale",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 188.0, 216.0, 49.0, 20.0 ],
									"id" : "obj-60",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"patcher" : 									{
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
										"boxes" : [ 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"patching_rect" : [ 110.0, 291.0, 25.0, 25.0 ],
													"id" : "obj-12",
													"numinlets" : 1,
													"numoutlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "f",
													"outlettype" : [ "float" ],
													"fontname" : "Arial",
													"patching_rect" : [ 231.0, 192.0, 32.5, 20.0 ],
													"id" : "obj-7",
													"numinlets" : 2,
													"numoutlets" : 1,
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-17", 0 ],
													"destination" : [ "obj-16", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-17", 0 ],
													"destination" : [ "obj-14", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-16", 0 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-14", 0 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-9", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 1 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 1 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-8", 2 ],
													"hidden" : 0,
													"midpoints" : [ 240.5, 236.5, 148.699997, 236.5 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-8", 1 ],
													"hidden" : 0,
													"midpoints" : [ 145.5, 231.0, 134.100006, 231.0 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [ 240.5, 222.0, 329.0, 222.0, 329.0, 151.0, 314.5, 151.0 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-7", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [ 145.5, 221.0, 224.0, 221.0, 224.0, 155.0, 212.5, 155.0 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-6", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
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
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 241.0, 166.0, 50.0, 20.0 ],
									"id" : "obj-5",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl sum",
									"outlettype" : [ "", "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 241.0, 139.0, 45.0, 20.0 ],
									"id" : "obj-3",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 50.0, 138.0, 50.0, 20.0 ],
									"id" : "obj-59",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "js vecMag.js 0",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 50.0, 100.0, 87.0, 20.0 ],
									"id" : "obj-53",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-127",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 343.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-128",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 167.0, 277.0, 25.0, 25.0 ],
									"id" : "obj-129",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 329.5, 516.0, 25.0, 25.0 ],
									"id" : "obj-130",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 241.0, 205.0, 25.0, 25.0 ],
									"id" : "obj-131",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-131", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-88", 0 ],
									"destination" : [ "obj-130", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-79", 0 ],
									"destination" : [ "obj-130", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-62", 0 ],
									"destination" : [ "obj-129", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-128", 0 ],
									"destination" : [ "obj-77", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-127", 0 ],
									"destination" : [ "obj-53", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-81", 0 ],
									"destination" : [ "obj-88", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-53", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-79", 1 ],
									"destination" : [ "obj-81", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-77", 0 ],
									"destination" : [ "obj-79", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-62", 0 ],
									"destination" : [ "obj-77", 0 ],
									"hidden" : 0,
									"midpoints" : [ 197.5, 379.5, 339.5, 379.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-60", 0 ],
									"hidden" : 0,
									"midpoints" : [ 250.5, 163.0, 197.5, 163.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-60", 0 ],
									"destination" : [ "obj-62", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-53", 0 ],
									"destination" : [ "obj-59", 0 ],
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
					"maxclass" : "number",
					"outlettype" : [ "int", "bang" ],
					"presentation_rect" : [ 1160.0, 506.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 1160.0, 506.0, 50.0, 20.0 ],
					"id" : "obj-145",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "mxj fuzzyArt 2 0. 0.2 0.83",
					"outlettype" : [ "", "", "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1200.0, 459.0, 146.0, 20.0 ],
					"id" : "obj-146",
					"numinlets" : 1,
					"numoutlets" : 4,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p CHARTS",
					"fontname" : "Arial",
					"patching_rect" : [ 1156.0, 414.0, 78.5, 20.0 ],
					"id" : "obj-142",
					"numinlets" : 6,
					"numoutlets" : 0,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 25.0, 69.0, 830.0, 683.0 ],
						"bglocked" : 0,
						"defrect" : [ 25.0, 69.0, 830.0, 683.0 ],
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
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"size" : 75,
									"setstyle" : 1,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 63.0, 487.0, 388.0, 152.0 ],
									"id" : "obj-123",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "is this a good intrinsic reward measure?",
									"linecount" : 2,
									"fontname" : "Arial",
									"patching_rect" : [ 593.0, 453.0, 150.0, 34.0 ],
									"id" : "obj-84",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 0.1 ],
									"patching_rect" : [ 543.0, 491.0, 212.0, 149.0 ],
									"id" : "obj-78",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "clip 0. 0.3",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 540.0, 46.0, 62.0, 20.0 ],
									"id" : "obj-76",
									"numinlets" : 3,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 0.3 ],
									"patching_rect" : [ 540.0, 74.0, 212.0, 149.0 ],
									"id" : "obj-75",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "amount of learning that is taking place per sample",
									"linecount" : 2,
									"fontname" : "Arial",
									"patching_rect" : [ 603.0, 35.0, 150.0, 34.0 ],
									"id" : "obj-73",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "looking for indication of novelty. high values indicate expected, low values=unexpected/new",
									"linecount" : 4,
									"fontname" : "Arial",
									"patching_rect" : [ 592.0, 233.0, 150.0, 62.0 ],
									"id" : "obj-72",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 84.0, 72.0, 50.0, 20.0 ],
									"id" : "obj-70",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"patching_rect" : [ 78.0, 129.0, 212.0, 149.0 ],
									"id" : "obj-68",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "- 0.",
									"outlettype" : [ "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 128.0, 99.0, 32.5, 20.0 ],
									"id" : "obj-67",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 299.0, 128.0, 212.0, 149.0 ],
									"id" : "obj-63",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"setstyle" : 3,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 539.0, 297.0, 212.0, 149.0 ],
									"id" : "obj-8",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "multislider",
									"outlettype" : [ "", "" ],
									"size" : 75,
									"setstyle" : 1,
									"setminmax" : [ 0.0, 1.0 ],
									"patching_rect" : [ 50.0, 286.0, 435.0, 152.0 ],
									"id" : "obj-1",
									"numinlets" : 1,
									"numoutlets" : 2
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-136",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "float" ],
									"patching_rect" : [ 127.5, 38.0, 25.0, 25.0 ],
									"id" : "obj-137",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "float" ],
									"patching_rect" : [ 543.0, 457.0, 25.0, 25.0 ],
									"id" : "obj-138",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 540.0, 16.0, 25.0, 25.0 ],
									"id" : "obj-139",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "float" ],
									"patching_rect" : [ 539.0, 262.0, 25.0, 25.0 ],
									"id" : "obj-140",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 63.0, 454.0, 25.0, 25.0 ],
									"id" : "obj-141",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-67", 0 ],
									"destination" : [ "obj-68", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-70", 0 ],
									"destination" : [ "obj-67", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-76", 0 ],
									"destination" : [ "obj-75", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-136", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-137", 0 ],
									"destination" : [ "obj-70", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-137", 0 ],
									"destination" : [ "obj-67", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-137", 0 ],
									"destination" : [ "obj-63", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-138", 0 ],
									"destination" : [ "obj-78", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-139", 0 ],
									"destination" : [ "obj-76", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-140", 0 ],
									"destination" : [ "obj-8", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-141", 0 ],
									"destination" : [ "obj-123", 0 ],
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
					"maxclass" : "newobj",
					"text" : "p intrinsicReward",
					"outlettype" : [ "float", "float", "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1033.0, 370.0, 104.0, 20.0 ],
					"id" : "obj-132",
					"numinlets" : 2,
					"numoutlets" : 3,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 25.0, 69.0, 542.0, 594.0 ],
						"bglocked" : 0,
						"defrect" : [ 25.0, 69.0, 542.0, 594.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "message",
									"text" : "0.",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 373.0, 482.0, 32.5, 18.0 ],
									"id" : "obj-88",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "comment",
									"text" : "residual * inverse novelty",
									"fontname" : "Arial",
									"patching_rect" : [ 368.0, 397.0, 150.0, 20.0 ],
									"id" : "obj-83",
									"numinlets" : 1,
									"numoutlets" : 0,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "button",
									"outlettype" : [ "bang" ],
									"patching_rect" : [ 373.0, 459.0, 20.0, 20.0 ],
									"id" : "obj-81",
									"numinlets" : 1,
									"numoutlets" : 1
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "split 0 0.3",
									"outlettype" : [ "float", "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 330.0, 434.0, 62.0, 20.0 ],
									"id" : "obj-79",
									"numinlets" : 3,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "* 0.",
									"outlettype" : [ "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 330.0, 397.0, 32.5, 20.0 ],
									"id" : "obj-77",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 188.0, 243.0, 50.0, 20.0 ],
									"id" : "obj-62",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "p scale",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 188.0, 216.0, 49.0, 20.0 ],
									"id" : "obj-60",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 12.0,
									"patcher" : 									{
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
										"boxes" : [ 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
													"maxclass" : "outlet",
													"patching_rect" : [ 110.0, 291.0, 25.0, 25.0 ],
													"id" : "obj-12",
													"numinlets" : 1,
													"numoutlets" : 0,
													"comment" : ""
												}

											}
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
													"maxclass" : "newobj",
													"text" : "f",
													"outlettype" : [ "float" ],
													"fontname" : "Arial",
													"patching_rect" : [ 231.0, 192.0, 32.5, 20.0 ],
													"id" : "obj-7",
													"numinlets" : 2,
													"numoutlets" : 1,
													"fontsize" : 12.0
												}

											}
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
, 											{
												"box" : 												{
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
										"lines" : [ 											{
												"patchline" : 												{
													"source" : [ "obj-2", 0 ],
													"destination" : [ "obj-6", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [ 145.5, 221.0, 224.0, 221.0, 224.0, 155.0, 212.5, 155.0 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-3", 0 ],
													"destination" : [ "obj-7", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [ 240.5, 222.0, 329.0, 222.0, 329.0, 151.0, 314.5, 151.0 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-8", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-6", 0 ],
													"destination" : [ "obj-8", 1 ],
													"hidden" : 0,
													"midpoints" : [ 145.5, 231.0, 134.100006, 231.0 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-7", 0 ],
													"destination" : [ "obj-8", 2 ],
													"hidden" : 0,
													"midpoints" : [ 240.5, 236.5, 148.699997, 236.5 ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 1 ],
													"destination" : [ "obj-3", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-9", 1 ],
													"destination" : [ "obj-2", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-1", 0 ],
													"destination" : [ "obj-9", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-8", 0 ],
													"destination" : [ "obj-12", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-14", 0 ],
													"destination" : [ "obj-2", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-16", 0 ],
													"destination" : [ "obj-3", 1 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-17", 0 ],
													"destination" : [ "obj-14", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
, 											{
												"patchline" : 												{
													"source" : [ "obj-17", 0 ],
													"destination" : [ "obj-16", 0 ],
													"hidden" : 0,
													"midpoints" : [  ]
												}

											}
 ]
									}
,
									"saved_object_attributes" : 									{
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
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 241.0, 166.0, 50.0, 20.0 ],
									"id" : "obj-5",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl sum",
									"outlettype" : [ "", "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 241.0, 139.0, 45.0, 20.0 ],
									"id" : "obj-3",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "flonum",
									"outlettype" : [ "float", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 50.0, 138.0, 50.0, 20.0 ],
									"id" : "obj-59",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "js vecMag.js 0",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 50.0, 100.0, 87.0, 20.0 ],
									"id" : "obj-53",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-127",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "" ],
									"patching_rect" : [ 343.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-128",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 167.0, 277.0, 25.0, 25.0 ],
									"id" : "obj-129",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 329.5, 516.0, 25.0, 25.0 ],
									"id" : "obj-130",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 241.0, 205.0, 25.0, 25.0 ],
									"id" : "obj-131",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-53", 0 ],
									"destination" : [ "obj-59", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-5", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-60", 0 ],
									"destination" : [ "obj-62", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-60", 0 ],
									"hidden" : 0,
									"midpoints" : [ 250.5, 163.0, 197.5, 163.0 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-62", 0 ],
									"destination" : [ "obj-77", 0 ],
									"hidden" : 0,
									"midpoints" : [ 197.5, 379.5, 339.5, 379.5 ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-77", 0 ],
									"destination" : [ "obj-79", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-79", 1 ],
									"destination" : [ "obj-81", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-53", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-81", 0 ],
									"destination" : [ "obj-88", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-127", 0 ],
									"destination" : [ "obj-53", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-128", 0 ],
									"destination" : [ "obj-77", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-62", 0 ],
									"destination" : [ "obj-129", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-79", 0 ],
									"destination" : [ "obj-130", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-88", 0 ],
									"destination" : [ "obj-130", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-5", 0 ],
									"destination" : [ "obj-131", 0 ],
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
					"maxclass" : "button",
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 989.0, 111.0, 20.0, 20.0 ],
					"id" : "obj-122",
					"numinlets" : 1,
					"numoutlets" : 1
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "sel 1",
					"outlettype" : [ "bang", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 177.0, 107.0, 36.0, 20.0 ],
					"id" : "obj-120",
					"numinlets" : 2,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "counter 12",
					"outlettype" : [ "int", "", "", "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 177.0, 80.0, 73.0, 20.0 ],
					"id" : "obj-119",
					"numinlets" : 5,
					"numoutlets" : 4,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "number",
					"outlettype" : [ "int", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 428.0, 79.0, 50.0, 20.0 ],
					"id" : "obj-118",
					"numinlets" : 1,
					"numoutlets" : 2,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* 0.01",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 372.0, 79.0, 42.0, 20.0 ],
					"id" : "obj-116",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "drunk 100 6",
					"outlettype" : [ "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 372.0, 53.0, 74.0, 20.0 ],
					"id" : "obj-115",
					"numinlets" : 3,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "to avoid a big spike in \"interest\" when a new category is created we set all new categories to 0-which is they're typical value when weighted by observation count.",
					"linecount" : 7,
					"fontname" : "Arial",
					"patching_rect" : [ 790.0, 27.0, 154.0, 103.0 ],
					"id" : "obj-114",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "gswitch2",
					"outlettype" : [ "", "" ],
					"int" : 1,
					"patching_rect" : [ 177.0, 41.0, 39.0, 32.0 ],
					"id" : "obj-112",
					"numinlets" : 2,
					"numoutlets" : 2
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "* 0.001",
					"outlettype" : [ "float" ],
					"fontname" : "Arial",
					"patching_rect" : [ 267.0, 80.0, 49.0, 20.0 ],
					"id" : "obj-111",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "random 1000",
					"outlettype" : [ "int" ],
					"fontname" : "Arial",
					"patching_rect" : [ 268.0, 55.0, 81.0, 20.0 ],
					"id" : "obj-110",
					"numinlets" : 2,
					"numoutlets" : 1,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Register Velocity",
					"linecount" : 2,
					"presentation_rect" : [ 888.0, 273.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 896.0, 249.0, 84.0, 48.0 ],
					"id" : "obj-100",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 18.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Register",
					"presentation_rect" : [ 684.0, 253.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 719.0, 261.0, 78.0, 27.0 ],
					"id" : "obj-99",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 18.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Interval Class STM",
					"presentation_rect" : [ 641.0, 449.0, 0.0, 0.0 ],
					"fontname" : "Arial",
					"patching_rect" : [ 641.0, 449.0, 221.0, 27.0 ],
					"id" : "obj-98",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 18.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "comment",
					"text" : "Pitch Class STM",
					"fontname" : "Arial",
					"patching_rect" : [ 382.0, 454.0, 221.0, 27.0 ],
					"id" : "obj-97",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 18.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "newobj",
					"text" : "p inputProcessing",
					"outlettype" : [ "", "", "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 377.0, 256.5, 201.0, 20.0 ],
					"id" : "obj-95",
					"numinlets" : 2,
					"numoutlets" : 4,
					"fontsize" : 12.0,
					"patcher" : 					{
						"fileversion" : 1,
						"rect" : [ 100.0, 566.0, 756.0, 594.0 ],
						"bglocked" : 0,
						"defrect" : [ 100.0, 566.0, 756.0, 594.0 ],
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
						"boxes" : [ 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "zl join",
									"outlettype" : [ "", "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 211.0, 437.0, 41.0, 20.0 ],
									"id" : "obj-3",
									"numinlets" : 2,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "pack f f",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 481.0, 389.0, 49.0, 20.0 ],
									"id" : "obj-2",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "clip 0. 1.",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 605.0, 338.0, 55.0, 20.0 ],
									"id" : "obj-1",
									"numinlets" : 3,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "scale -4. 4. 0. 1.",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 605.0, 307.5, 96.0, 20.0 ],
									"id" : "obj-48",
									"numinlets" : 6,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t f f",
									"outlettype" : [ "float", "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 605.0, 252.5, 32.5, 20.0 ],
									"id" : "obj-47",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "- 0.",
									"outlettype" : [ "float" ],
									"fontname" : "Arial",
									"patching_rect" : [ 605.0, 280.5, 32.5, 20.0 ],
									"id" : "obj-46",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "abs",
									"outlettype" : [ "int" ],
									"fontname" : "Arial",
									"patching_rect" : [ 211.0, 192.5, 30.0, 20.0 ],
									"id" : "obj-45",
									"numinlets" : 1,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "scale 0. 48. 0. 1.",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 421.0, 297.5, 99.0, 20.0 ],
									"id" : "obj-43",
									"numinlets" : 6,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "number",
									"outlettype" : [ "int", "bang" ],
									"fontname" : "Arial",
									"patching_rect" : [ 211.0, 270.5, 50.0, 20.0 ],
									"id" : "obj-35",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "!- 12",
									"outlettype" : [ "int" ],
									"fontname" : "Arial",
									"patching_rect" : [ 244.0, 245.5, 35.0, 20.0 ],
									"id" : "obj-33",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "split 0 6",
									"outlettype" : [ "int", "int" ],
									"fontname" : "Arial",
									"patching_rect" : [ 211.0, 219.5, 52.0, 20.0 ],
									"id" : "obj-32",
									"numinlets" : 3,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "% 12",
									"outlettype" : [ "int" ],
									"fontname" : "Arial",
									"patching_rect" : [ 211.0, 158.5, 38.0, 20.0 ],
									"id" : "obj-31",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "js linearSTM.js 0.15 7",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 211.0, 295.5, 126.0, 20.0 ],
									"id" : "obj-29",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "t i i",
									"outlettype" : [ "int", "int" ],
									"fontname" : "Arial",
									"patching_rect" : [ 211.0, 106.5, 32.5, 20.0 ],
									"id" : "obj-28",
									"numinlets" : 1,
									"numoutlets" : 2,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "-",
									"outlettype" : [ "int" ],
									"fontname" : "Arial",
									"patching_rect" : [ 211.0, 133.5, 32.5, 20.0 ],
									"id" : "obj-27",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "i",
									"outlettype" : [ "int" ],
									"fontname" : "Arial",
									"patching_rect" : [ 50.0, 273.5, 32.5, 20.0 ],
									"id" : "obj-26",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "newobj",
									"text" : "js linearSTM.js 0.15",
									"outlettype" : [ "" ],
									"fontname" : "Arial",
									"patching_rect" : [ 50.0, 301.5, 116.0, 20.0 ],
									"id" : "obj-22",
									"numinlets" : 2,
									"numoutlets" : 1,
									"fontsize" : 12.0
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "float" ],
									"patching_rect" : [ 50.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-89",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "inlet",
									"outlettype" : [ "int" ],
									"patching_rect" : [ 421.0, 40.0, 25.0, 25.0 ],
									"id" : "obj-90",
									"numinlets" : 0,
									"numoutlets" : 1,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 50.0, 387.5, 25.0, 25.0 ],
									"id" : "obj-91",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 211.0, 539.5, 25.0, 25.0 ],
									"id" : "obj-92",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 421.0, 387.5, 25.0, 25.0 ],
									"id" : "obj-93",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
, 							{
								"box" : 								{
									"maxclass" : "outlet",
									"patching_rect" : [ 605.0, 387.5, 25.0, 25.0 ],
									"id" : "obj-94",
									"numinlets" : 1,
									"numoutlets" : 0,
									"comment" : ""
								}

							}
 ],
						"lines" : [ 							{
								"patchline" : 								{
									"source" : [ "obj-3", 0 ],
									"destination" : [ "obj-92", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-29", 0 ],
									"destination" : [ "obj-3", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-2", 0 ],
									"destination" : [ "obj-3", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-2", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-43", 0 ],
									"destination" : [ "obj-2", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-48", 0 ],
									"destination" : [ "obj-1", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-1", 0 ],
									"destination" : [ "obj-94", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-46", 0 ],
									"destination" : [ "obj-48", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-90", 0 ],
									"destination" : [ "obj-47", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-47", 1 ],
									"destination" : [ "obj-46", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-47", 0 ],
									"destination" : [ "obj-46", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-45", 0 ],
									"destination" : [ "obj-32", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-31", 0 ],
									"destination" : [ "obj-45", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-35", 0 ],
									"destination" : [ "obj-29", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-32", 0 ],
									"destination" : [ "obj-35", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-33", 0 ],
									"destination" : [ "obj-35", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-32", 1 ],
									"destination" : [ "obj-33", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-27", 0 ],
									"destination" : [ "obj-31", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-26", 0 ],
									"destination" : [ "obj-28", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-28", 1 ],
									"destination" : [ "obj-27", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-28", 0 ],
									"destination" : [ "obj-27", 1 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-26", 0 ],
									"destination" : [ "obj-22", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-89", 0 ],
									"destination" : [ "obj-26", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-90", 0 ],
									"destination" : [ "obj-43", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-22", 0 ],
									"destination" : [ "obj-91", 0 ],
									"hidden" : 0,
									"midpoints" : [  ]
								}

							}
, 							{
								"patchline" : 								{
									"source" : [ "obj-43", 0 ],
									"destination" : [ "obj-93", 0 ],
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
					"size" : 306,
					"setstyle" : 1,
					"presentation_rect" : [ 423.0, 632.0, 0.0, 0.0 ],
					"setminmax" : [ 0.0, 1.0 ],
					"patching_rect" : [ 407.0, 812.0, 155.0, 43.0 ],
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
					"patching_rect" : [ 123.0, 760.0, 50.0, 20.0 ],
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
					"patching_rect" : [ 187.0, 813.0, 212.0, 149.0 ],
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
					"patching_rect" : [ 187.0, 780.0, 50.0, 20.0 ],
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
					"patching_rect" : [ 187.0, 753.0, 45.0, 20.0 ],
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
					"outlettype" : [ "", "", "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 123.0, 724.0, 146.0, 20.0 ],
					"id" : "obj-38",
					"numinlets" : 1,
					"numoutlets" : 4,
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
					"text" : "mxj fuzzyArt 7 0. 0.2 0.84",
					"outlettype" : [ "", "", "", "" ],
					"fontname" : "Arial",
					"patching_rect" : [ 1019.0, 333.0, 146.0, 20.0 ],
					"id" : "obj-52",
					"numinlets" : 1,
					"numoutlets" : 4,
					"fontsize" : 12.0
				}

			}
, 			{
				"box" : 				{
					"maxclass" : "flonum",
					"outlettype" : [ "float", "bang" ],
					"fontname" : "Arial",
					"patching_rect" : [ 914.0, 294.0, 50.0, 20.0 ],
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
					"maxclass" : "multislider",
					"outlettype" : [ "", "" ],
					"size" : 9,
					"setminmax" : [ 0.0, 1.0 ],
					"patching_rect" : [ 631.0, 319.0, 261.0, 132.0 ],
					"id" : "obj-30",
					"numinlets" : 1,
					"numoutlets" : 2
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
					"patching_rect" : [ 351.0, 206.0, 50.0, 20.0 ],
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
					"patching_rect" : [ 339.0, 176.0, 32.5, 20.0 ],
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
					"patching_rect" : [ 339.0, 151.0, 96.0, 20.0 ],
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
					"patching_rect" : [ 404.0, 126.0, 150.0, 20.0 ],
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
					"patching_rect" : [ 339.0, 121.0, 50.0, 20.0 ],
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
					"patching_rect" : [ 10.0, 7.0, 150.0, 20.0 ],
					"id" : "obj-2",
					"numinlets" : 1,
					"numoutlets" : 0,
					"fontsize" : 12.0
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"source" : [ "obj-120", 0 ],
					"destination" : [ "obj-115", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-152", 1 ],
					"destination" : [ "obj-149", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1143.833374, 594.5, 1238.5, 594.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-152", 2 ],
					"destination" : [ "obj-149", 4 ],
					"hidden" : 0,
					"midpoints" : [ 1186.166626, 594.5, 1286.099976, 594.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-152", 3 ],
					"destination" : [ "obj-149", 1 ],
					"hidden" : 0,
					"midpoints" : [ 1228.5, 594.5, 1250.400024, 594.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-152", 1 ],
					"destination" : [ "obj-150", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-152", 2 ],
					"destination" : [ "obj-150", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-152", 0 ],
					"destination" : [ "obj-151", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-148", 0 ],
					"destination" : [ "obj-152", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-146", 3 ],
					"destination" : [ "obj-152", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1336.5, 483.5, 1101.5, 483.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-147", 0 ],
					"destination" : [ "obj-146", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-146", 0 ],
					"destination" : [ "obj-145", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-146", 2 ],
					"destination" : [ "obj-144", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-146", 1 ],
					"destination" : [ "obj-144", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-146", 3 ],
					"destination" : [ "obj-143", 1 ],
					"hidden" : 0,
					"midpoints" : [ 1336.5, 490.5, 1358.400024, 490.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-146", 2 ],
					"destination" : [ "obj-143", 4 ],
					"hidden" : 0,
					"midpoints" : [ 1294.166626, 490.5, 1394.099976, 490.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-146", 1 ],
					"destination" : [ "obj-143", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1251.833374, 490.5, 1346.5, 490.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 3 ],
					"destination" : [ "obj-146", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1155.5, 445.5, 1209.5, 445.5 ]
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
					"source" : [ "obj-57", 0 ],
					"destination" : [ "obj-52", 0 ],
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
					"source" : [ "obj-95", 1 ],
					"destination" : [ "obj-52", 0 ],
					"hidden" : 0,
					"midpoints" : [ 447.166656, 285.25, 1028.5, 285.25 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 2 ],
					"destination" : [ "obj-132", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 1 ],
					"destination" : [ "obj-132", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 3 ],
					"destination" : [ "obj-142", 1 ],
					"hidden" : 0,
					"midpoints" : [ 1155.5, 364.5, 1177.400024, 364.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 2 ],
					"destination" : [ "obj-142", 4 ],
					"hidden" : 0,
					"midpoints" : [ 1113.166626, 364.5, 1213.099976, 364.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-52", 1 ],
					"destination" : [ "obj-142", 0 ],
					"hidden" : 0,
					"midpoints" : [ 1070.833374, 364.5, 1165.5, 364.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-150", 0 ],
					"destination" : [ "obj-149", 2 ],
					"hidden" : 0,
					"midpoints" : [ 1115.5, 633.0, 1262.300049, 633.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-150", 2 ],
					"destination" : [ "obj-149", 5 ],
					"hidden" : 0,
					"midpoints" : [ 1200.5, 633.0, 1298.0, 633.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-150", 1 ],
					"destination" : [ "obj-149", 3 ],
					"hidden" : 0,
					"midpoints" : [ 1158.0, 633.0, 1274.199951, 633.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-144", 1 ],
					"destination" : [ "obj-143", 3 ],
					"hidden" : 0,
					"midpoints" : [ 1266.0, 529.0, 1382.199951, 529.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-144", 2 ],
					"destination" : [ "obj-143", 5 ],
					"hidden" : 0,
					"midpoints" : [ 1308.5, 529.0, 1406.0, 529.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-144", 0 ],
					"destination" : [ "obj-143", 2 ],
					"hidden" : 0,
					"midpoints" : [ 1223.5, 529.0, 1370.300049, 529.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-132", 0 ],
					"destination" : [ "obj-142", 2 ],
					"hidden" : 0,
					"midpoints" : [ 1042.5, 403.0, 1189.300049, 403.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-132", 2 ],
					"destination" : [ "obj-142", 5 ],
					"hidden" : 0,
					"midpoints" : [ 1127.5, 403.0, 1225.0, 403.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-132", 1 ],
					"destination" : [ "obj-142", 3 ],
					"hidden" : 0,
					"midpoints" : [ 1085.0, 403.0, 1201.199951, 403.0 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-95", 1 ],
					"destination" : [ "obj-30", 0 ],
					"hidden" : 0,
					"midpoints" : [ 447.166656, 297.25, 640.5, 297.25 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-38", 3 ],
					"destination" : [ "obj-58", 0 ],
					"hidden" : 0,
					"midpoints" : [ 259.5, 750.5, 416.5, 750.5 ]
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
					"source" : [ "obj-38", 0 ],
					"destination" : [ "obj-54", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-95", 0 ],
					"destination" : [ "obj-38", 0 ],
					"hidden" : 0,
					"midpoints" : [ 386.5, 499.75, 132.5, 499.75 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-122", 0 ],
					"destination" : [ "obj-18", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-112", 1 ],
					"destination" : [ "obj-119", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-119", 2 ],
					"destination" : [ "obj-120", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-115", 0 ],
					"destination" : [ "obj-118", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-115", 0 ],
					"destination" : [ "obj-116", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-116", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-9", 0 ],
					"destination" : [ "obj-112", 1 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-111", 0 ],
					"destination" : [ "obj-4", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-110", 0 ],
					"destination" : [ "obj-111", 0 ],
					"hidden" : 0,
					"midpoints" : [  ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-15", 0 ],
					"destination" : [ "obj-95", 0 ],
					"hidden" : 0,
					"midpoints" : [ 121.5, 371.0, 254.0, 371.0, 254.0, 246.5, 386.5, 246.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-14", 0 ],
					"destination" : [ "obj-95", 1 ],
					"hidden" : 0,
					"midpoints" : [ 121.5, 355.0, 248.0, 355.0, 248.0, 241.5, 568.5, 241.5 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-95", 0 ],
					"destination" : [ "obj-23", 0 ],
					"hidden" : 0,
					"midpoints" : [ 386.5, 297.75, 368.5, 297.75 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-95", 2 ],
					"destination" : [ "obj-50", 0 ],
					"hidden" : 0,
					"midpoints" : [ 507.833344, 282.25, 739.5, 282.25 ]
				}

			}
, 			{
				"patchline" : 				{
					"source" : [ "obj-95", 3 ],
					"destination" : [ "obj-51", 0 ],
					"hidden" : 0,
					"midpoints" : [ 568.5, 287.25, 923.5, 287.25 ]
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
					"source" : [ "obj-37", 0 ],
					"destination" : [ "obj-11", 0 ],
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
 ]
	}

}
