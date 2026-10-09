# Java Abstract Class

Platform: HackerRank  
Difficulty: Practice  
Language: Java 7  
Problem Link: https://www.hackerrank.com/contests/fp2-batch1-q2-1791368290/challenges/java-abstract-class/problem?isFullScreen=true  
Submitted At: 2026-10-09

---

## Description

<div class="challenge_problem_statement"><div class="msB challenge_problem_statement_body"><div class="hackdown-content"><svg style="display: none;"><defs id="MathJax_SVG_glyphs"></defs></svg><p>A Java abstract class is a class that can't be instantiated. That means you cannot create new instances of an abstract class. It works as a base for subclasses. You should learn about Java Inheritance before attempting this challenge. </p>

<p>Following is an example of abstract class:</p>

<div class="highlight"><pre><span class="kd">abstract</span> <span class="kd">class</span> <span class="nc">Book</span><span class="o">{</span>
    <span class="n">String</span> <span class="n">title</span><span class="o">;</span>
    <span class="kd">abstract</span> <span class="kt">void</span> <span class="nf">setTitle</span><span class="o">(</span><span class="n">String</span> <span class="n">s</span><span class="o">);</span>
    <span class="n">String</span> <span class="nf">getTitle</span><span class="o">(){</span>
        <span class="k">return</span> <span class="n">title</span><span class="o">;</span>
    <span class="o">}</span>
<span class="o">}</span>
</pre></div>


<p>If you try to create an instance of this class like the following line you will get an error:</p>

<div class="highlight"><pre><span class="n">Book</span> <span class="n">new_novel</span><span class="o">=</span><span class="k">new</span> <span class="n">Book</span><span class="o">();</span> 
</pre></div>


<p>You have to create another class that extends the abstract class. Then you can create an instance of the new class. </p>

<p>Notice that <em>setTitle</em> method is abstract too and has no body. That means you must implement the body of that method in the child class.</p>

<p>In the editor, we have provided the abstract <em>Book</em> class and a <em>Main</em> class. In the Main class, we created an instance of a class called <em>MyBook</em>. Your task is to write just the <em>MyBook</em> class. </p>

<p>Your class mustn't be public.</p>

<p><strong>Sample Input</strong></p>

<pre><code>A tale of two cities
</code></pre>

<p><strong>Sample Output</strong></p>

<pre><code>The title is: A tale of two cities
</code></pre></div></div></div>
