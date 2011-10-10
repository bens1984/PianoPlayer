import com.cycling74.max.*;

//
// fuzzy Adaptive Resonance Theory Implementation in java for max
//			2010, Benjamin Smith <ben@musicsmiths.us> - GPL license.
//				http://ben.musicsmiths.us/
//		based on Carpenter and Grossberg - search on google scholar
//
//  arguments are: Choice, learn rate and Vigilance
//
//  parameters:
//		distance boolean - if true outputs accuracy of the input, how close it hits the center of the known category

// 2011, September: this version counts how often a category is observed and outputs importance as resonance*observation count
//		thus frequently seen categories will be weighted much heigher than new or infrequently seen ones
//		this should be a measure of the 'importance' of a category, in a sense

//  9/30/2011 BDS - calculating residual for each learning step and outputing out outlet 2. This is just a simple difference
//      but maybe it should be a magnitude of difference? I'm not sure which is appropriate or problematic at this point.

// BDS NOTE!!!! - when the input length increases all of the categories are extended and immediately 'learn' the new
//      dimension as a value of 0 (effectively we always assume an infinite number of dimensions with no information, i.e. 0)
//      if they should instead be treated as null (set dimension and its complement code to 1) then change it in
//      Category::resizeCategory (at end, weighting[i] = x.x)

public class fuzzyArt extends MaxObject
	{
		private art myArt;
		private int mDimensions;
		private double mChoice, mLearnRate, mVigilance;	// store for reset
		private boolean mDistance;
		
		private static final String[] INLET_ASSIST = new String[]{
		"input feature vector in (double list)"
		};
		private static final String[] OUTLET_ASSIST = new String[]{
		"match out", "importance out", "residual out", "resonance out"
		};
		
		public fuzzyArt(int dimensions, double _choice, double _learnRate, double _Vigilance)
		{
			declareInlets(new int[]{DataTypes.ALL});
			declareOutlets(new int[]{DataTypes.ALL,DataTypes.ALL,DataTypes.ALL});
			
			setInletAssist(INLET_ASSIST);
			setOutletAssist(OUTLET_ASSIST);
			
			mDimensions = (dimensions > 0 ? dimensions : 1);
			mLearnRate = (_learnRate != 0 ? _learnRate : 0.5);
			mChoice = _choice;
			mVigilance = _Vigilance;
			mDistance = false;
			
			myArt = new art(dimensions, _choice, _learnRate, _Vigilance);
			post("FuzzyART -- implementation ©2010 Benjamin Smith");
			post(" init with Dimensions: " + dimensions + ", Choice: " + _choice + ", Learn Rate: " + mLearnRate + ", Vigilance: " + _Vigilance);
		}
		
		//	public void bang()	// output category 0 weights
		//	{
		////		outlet(0,mCategories[0].GetWeights());
		//	}
		
		public void inlet(int i)
		{
			myArt.outputCategoryWeight(i);
		}
		
		// ---------------- public accessors 
		// set vigilance
		public void vigilance(double v)
		{
			mVigilance = (v >= 0 ? (v <= 1 ? v : 1) : 0);
			myArt.setVigilance(mVigilance);
		}
		// set learn rate
		public void learnRate(double v)
		{
			mLearnRate = (v >= 0 ? (v <= 1 ? v : 1) : 0);
			myArt.setLearnRate(mLearnRate);
		}
		// set choice
		public void choice(double v)
		{
			mChoice = (v >= 0 ? (v <= 1 ? v : 1) : 0);
			myArt.setChoice(mChoice);
		}
		
		public void distance(boolean b)
		{
			mDistance = b;
		}
		
		// ---------------- List: input of new feature vector
		public void list(Atom[] list)
		{
//			if (list.length == mDimensions)	// we have new input! start checking categories.
//			{
				double[] input = new double[list.length];
				for (int i = 0; i < list.length; i++)
					if (list[i].isInt())
						input[i] = list[i].getInt();
					else if (list[i].isFloat())
						input[i] = list[i].getFloat();
					else input[i] = 0.0f;
				
				myArt.setInput(input);
				myArt.normalizeInput();
				myArt.complementCode();
				double[] fitVector = myArt.getCategoryChoice();
            double[] importance = myArt.getImportance();
            
            outlet(3, Atom.newAtom(fitVector));                 // output resonance of input with all categories
            
				int chosenCat = myArt.makeChoice();	// make a choice and learn from it
            
							
				if (mDistance && chosenCat >= 0)
					outlet(2, Atom.newAtom(myArt.calcDistance(chosenCat)));	// output the distance of this input to the center of its category
                else
                    outlet(2, Atom.newAtom(myArt.getResidual()));
                       
                if (importance != null)
                    outlet(1, Atom.newAtom(importance));	// output importance (resonance * observation count) of all nodes for the given input
				outlet(0, Atom.newAtom(chosenCat));	// output the chosen category!
//			} else
//				post("error! input dimensions don't match dimension argument.");
		}
		
		//	private void outputChoices(int iter, double[] choices)
		//	{
		//		Atom[] out = new Atom[choices.length+1];
		//		out[0] = Atom.newAtom(iter);
		//		for(int i = 0; i < choices.length; i++)
		//			out[i+1] = Atom.newAtom(choices[i]);
		//		outlet(2, "iter", out);
		//	}
		
		private void outputInitialWeights(double[] choices)
		{
			Atom[] out = new Atom[choices.length];
			for(int i = 0; i < choices.length; i++)
				out[i] = Atom.newAtom(choices[i]);
			outlet(1, out);
		}
		
		public void IncreaseVigilance()
		{
			int out = myArt.increaseVigilance();
			outlet(0, out);
		}
		
		public void categories()
		{
			double[][] weights = myArt.getWeights();
			for (int i = 0; i < weights.length; i++)
			{
				Atom[] out = Atom.newAtom(weights[i]);
				outlet(2, (String)Integer.toString(i), out);
			}
		}
		
		public void centers()
		{
			double[][] weights = myArt.getWeights();
			for (int i = 0; i < weights.length; i++)
			{
				double[] centers = new double[mDimensions];	// calculate the center positions of the weights
				for (int j = 0; j < mDimensions; j++)	// same as mDimensions
					centers[j] = (weights[i][j] + weights[i][j+mDimensions]) * 0.5;
				Atom[] out = Atom.newAtom(centers);
				outlet(2, (String)Integer.toString(i), out);
			}
		}
		
		public void reset()
		{
			post("> reset fuzzyArt with Dimensions: " + mDimensions + ", Choice: " + mChoice + ", Learn Rate: " + mLearnRate + ", Vigilance: " + mVigilance);
			myArt = new art(mDimensions, mChoice, mLearnRate, mVigilance);
		}
		
		class art
			{
				private int mDimensions; // how many dimensions to match data on
				private category[] mCategories = new category[16];
				private int[] mCount = new int[16];	// record how many times each category has been seen
				private int inputCount;	// how many inputs we have processed, total
				private int categoryCount = 0;
				private double mChoice, mLearnRate, mVigilance;
				private double[] input;
				private double[] choices = new double[1];
				private int recentChoice;	// the most recently chosen category
                private double residual;    // how much the given category changed with the last input/learning step
				
				public art(int dimensions, double _choice, double _learnRate, double _Vigilance)
				{
					mDimensions = dimensions;
					
					mCategories[0] = new category(mDimensions);
					categoryCount = 1;
					inputCount = 0;
					
					input = new double[mDimensions*2];
					
					mChoice = _choice;
					mLearnRate = _learnRate;
					mVigilance = _Vigilance;
					recentChoice = -1;
				}
				
				public void setInput(double[] in)
				{
                    // check that input is the right length, otherwise adjust all known categories!
                    if (in.length > mDimensions)
                    {
                        mDimensions = in.length;
                        input = (double[])resizeArray(input, mDimensions*2);
                        for (int i = 0; i < categoryCount; i++)
                            mCategories[i].resizeCategory(mDimensions*2);
                    }
                    
                    for (int i = 0; i < in.length; i++)
                    {
                        input[i*2] = in[i]; // leave space for complemnt coding
                    }
//					System.arraycopy(in, 0, input, 0, in.length);
				}
				public void setVigilance(double v)
				{
					mVigilance = v;
				}
				public void setLearnRate(double v)
				{
					mLearnRate = v;
				}
				public void setChoice(double v)
				{
					mChoice = v;
				}
                public double getResidual()
                {
                    return residual;
                }
				
				public void normalizeInput()
				{			
					// limit input to [0,1] - normalize the input vector
					double max = 0;
					for (int i = 0; i < mDimensions; i++)
						max = (input[i] > max ? input[i] : max);
					if (max > 1)
					{
						for (int i = 0; i < mDimensions; i++)
							input[i] /= max;
					}
				}
				
				public void complementCode()    // this should be done to every input, or else the ART won't really work.
				{
					for (int i = 0; i < mDimensions*2; i += 2)	// create complement of input - complement coding
						input[i+1] = 1.0f - input[i];
				}
				
				public double[] getCategoryChoice()
				{
					// check against all existing categories, and 1 empty one
					if (input.length > 0)
					{
                        if (categoryCount > choices.length)
                            choices = new double[categoryCount];
						for (int i = 0; i < categoryCount; i++)
						{
							choices[i] = mCategories[i].Choose(input,mChoice);
						}
					} else
						for (int i = 0; i < categoryCount; i++)
                            choices[i] = 0;
					return choices;
				}
				public double[] getImportance()
				{
                    if (inputCount > 0)
                    {
                        double[] importance = new double[categoryCount];
                        for (int i = 0; i < categoryCount; i++)
                            importance[i] = choices[i] * (mCount[i] / (double)inputCount);
                        return importance;
                    } else
                        return null;
				}
				public int makeChoice()
				{
					return makeChoice(mVigilance);
				}
				public int makeChoice(double workingVigilance)
				{
					int maxIndex = -1;
					int iter = 0;
					boolean chosen = false;		// check mVigilance stuff here...
					while (!chosen)
					{
						// find largest match value
						double max = 0;
						for (int i = 0; i < categoryCount; i++)
							if (choices[i] > max)
							{
								max = choices[i];
								maxIndex = i;
							}
						if (maxIndex != -1)
						{
							// if above vigilence then learn from it
							if (mCategories[maxIndex].mVigilance(input,workingVigilance) || categoryCount == 1)		// learn!
							{
								residual = mCategories[maxIndex].Learn(input,mLearnRate); //learn, store residual for later output
								if (maxIndex == categoryCount-1)	// committed the previous uncommitted category, so add a new blank one.
								{	
									if (categoryCount+1 >= mCategories.length)
									{
										mCategories = (category[])resizeArray(mCategories, mCategories.length + 16);
										mCount = (int[])resizeArray(mCount, mCategories.length + 16);
									}
									mCategories[categoryCount++] = new category(mDimensions);
								}
								chosen = true;
								recentChoice = maxIndex;
							}
							else	// failed the mVigilance test.
							{
								choices[maxIndex] = -1; // reset, try again
								maxIndex = -1;
							}
						} else
							chosen = true;
					}	// otherwise look again.
					if (maxIndex > -1)
					{
						inputCount++;
						mCount[maxIndex]++;
					}
					return maxIndex;
				}
				//	set the mVigilance just high enough to reset the chosen category and look again.
				public int increaseVigilance()
				{
					if (recentChoice > -1)
					{
						double vig = mCategories[recentChoice].GetVigilance(input) + 0.01f;	// increase by a little bit.
						recentChoice = makeChoice(vig);
					}
					return recentChoice;
				}
				public void outputCategoryWeight(int i)
				{
					if (i>= 0 && i < mCategories.length)
						outlet(2, mCategories[i].GetWeights());
				}
				/**
				 * Reallocates an array with a new size, and copies the contents
				 * of the old array to the new array.
				 * @param oldArray  the old array, to be reallocated.
				 * @param newSize   the new array size.
				 * @return          A new array with the same contents.
				 */
				private Object resizeArray (Object oldArray, int newSize) 
				{
					int oldSize = java.lang.reflect.Array.getLength(oldArray);
					Class elementType = oldArray.getClass().getComponentType();
					Object newArray = java.lang.reflect.Array.newInstance(elementType,newSize);
					int preserveLength = Math.min(oldSize,newSize);
					if (preserveLength > 0)
						System.arraycopy (oldArray,0,newArray,0,preserveLength);
					return newArray; 
				}
				
				public double calcDistance(int cat)	// use set input and calculate distance to center of specified category
				{
					if (cat < mCategories.length)
						return mCategories[cat].distance(input);
					else
						return -1;
				}
				public double[][] getWeights()	// return all of the weights of all of our categories
				{
					double[][] weights = new double[categoryCount][mDimensions*2];
					for (int i = 0; i < categoryCount; i++)
						weights[i] = mCategories[i].GetWeights();
					return weights;
				}
			}
		
		// class representation of each discovered category in the ART algorithm (each Node)
		class category
			{
				private boolean committed = false;	// switch to true after the category is committed
				
				private double[] weighting;
				private double sum = 0;
				
				public category(int dim)
				{
					weighting = new double[dim * 2];	// * 2 to use complement vector
					for (int i = 0; i < weighting.length; i++)
						weighting[i] = 1;	// can set higher than one to force deeper category search
					sum = dim * 2;
				}
				
				// calculate the mChoice match factor for this category and the given input
				public double Choose(double[] input, double mChoice)
				{
					//if (!committed)
					double minTotal = 0;
					for (int i = 0; i < input.length; i++)
						minTotal += (input[i] < weighting[i] ? input[i] : weighting[i]);
					return minTotal / (mChoice + sum);
				}
				
				public boolean mVigilance(double[] input, double mVigilance)
				{
					double minTotal = 0;
					double inputTotal = 0;
					for (int i = 0; i < input.length; i++)
					{
						minTotal += (input[i] < weighting[i] ? input[i] : weighting[i]);
						inputTotal += input[i];
					}
					
					return (minTotal / inputTotal >= mVigilance);
				}
				public double GetVigilance(double[] input)
				{
					double minTotal = 0;
					double inputTotal = 0;
					for (int i = 0; i < input.length; i++)
					{
						minTotal += (input[i] < weighting[i] ? input[i] : weighting[i]);
						inputTotal += input[i];
					}
					return minTotal / inputTotal;
				}
				
				public double Learn(double[] input, double mLearnRate)
				{
                    double[] newWeighting = new double[weighting.length];
                    double residual = 0;
					if (!committed)
					{
						mLearnRate = 1;
						committed = true;
					}
					double inverseLearnRate = 1.0f - mLearnRate;
					for (int i = 0; i < input.length; i++)
						newWeighting[i] = mLearnRate * (input[i] < weighting[i] ? input[i] : weighting[i]) + inverseLearnRate * weighting[i];
                    // calculate residual
                    for (int i = 0; i < weighting.length; i++)
                    {
                        residual += Math.abs(newWeighting[i] - weighting[i]);
                        weighting[i] = newWeighting[i];
                    }
					sum = 0;	// now update the total for this category
					for (int i = 0; i < weighting.length; i++)
						sum += weighting[i];
                    return residual;
				}
				
				public double[] GetWeights()
				{
					return weighting;
				}
				
				public double distance(double[] input)
				{
					// take the not complemented part
					int featureLength = weighting.length / 2;	// how many elements in the pre-complement coded vector?
					double[] center = new double[featureLength];
					
					for (int i = 0; i < featureLength; i++)	// find the 'center' of the category
					{
						center[i] = (weighting[i] + (1.0 - weighting[i+featureLength])) * 0.5;
					}
					double dist = 0;
					for (int i = 0; i < center.length; i++)	// calculate the distance to the input
						dist += Math.pow(input[i]-center[i],2);
					if (dist > 0)
						dist = Math.sqrt(dist);
					return dist;
				}
				/**
				 * Reallocates an array with a new size, and copies the contents
				 * of the old array to the new array.
				 * @param oldArray  the old array, to be reallocated.
				 * @param newSize   the new array size.
				 * @return          A new array with the same contents.
				 */
				public void resizeCategory (int newSize) //Object oldArray, int newSize) 
				{
                    Object oldArray = weighting;
					int oldSize = java.lang.reflect.Array.getLength(oldArray);
					Class elementType = oldArray.getClass().getComponentType();
					Object newArray = java.lang.reflect.Array.newInstance(elementType,newSize);
					int preserveLength = Math.min(oldSize,newSize);
					if (preserveLength > 0)
						System.arraycopy (oldArray,0,newArray,0,preserveLength);
					weighting = (double[])newArray; 
                    for (int i = oldSize; i < newSize; i += 2)
                    {
                        weighting[i] = 0.0;
                        weighting[i+1] = 1.0;   // this is very specific, making each new dimension 'learned' at 0. Appropriate for nesting ARTs
                    }
				}
			}
	}














































