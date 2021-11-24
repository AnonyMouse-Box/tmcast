### Contributing

In all honesty as this is a personal project, I don't expect anyone else will contribute. This is more an exercise in setting aside reminders to myself about how I should approach this.
If however on the offchance somebody does, the following will hopefully help guide them to make a good job of it:

A note on comments, both in code and out of it. Firstly plain don't be offensive, thats what a code of conduct is for, ensure any comment you make is helpful and constructive. Secondly, I once read a really good article on the different kinds of comments and how they can be used to be both helpful and efficient. Yes, I've also heard the old addage that good code is self documenting, in fact I try to write my code like this as if the code can be made more obvious without sacrifice, then it should be. However good code is not enough, sometimes a good comment can save you half an hour of unnecessary confusion, or other times there is no obvious way to write the code and it needs some explanation. I will try to find and [link that article here](http://antirez.com/news/124) so we can all have a good read and be the better coders for it. [This article](http://www.catb.org/~esr/faqs/smart-questions.html) also seems useful, though doesn't really fit anywhere.

1. Study and gain a reasonable understanding of the subject matter, the aim of the project, and the purpose to be fulfilled.
2. Attempt to make contact with the repository owner. (I appreciate this may be hard for those who don't know me personally, but this project is inherently personal.)
3. Once you are able, choose a part of the project you can dedicate yourself to and provide some valuable insights.
4. You will require an unprotected branch to add your code to, it will most likely be easier if you create yourself an individual one. 
5. Be sure to pull in regular updates from the master branch, and keep an eye on the files most relevant to your section for any changes.
6. Always try to leave a helpful message with each commit, this makes it easier to unpick your code later and make sense of what you did and why.
7. When you believe your code is ready for use, submit a pull request, then sit back, relax, and prepare for the "What the hell *is* this garbage?!"

In terms of how to access the code and what tools to use I operate a Gitflow process, read about it [here](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow). So anything that works without breaking that will be good, for now I'll retain management of the branch structure, just let me know what you need and I'll make it for you. The main and develop branches are protected to protect the core structure of the code and limit CI/CD pipelines where I can use them to test the code before releasing. Access to them will be as described through hotfix, release and feature branches. Until release I'm pushing updates through hotfix branches to skip over the currently unnecessary steps as the code is as yet unstable so doesn't need protecting.

