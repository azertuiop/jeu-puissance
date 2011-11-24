var NAVTREE =
[
  [ "PUISSANCE4", "index.html", [
    [ "Liste des classes", "annotated.html", [
      [ "Couleur", "struct_couleur.html", null ],
      [ "Jeu", "struct_jeu.html", null ],
      [ "Puissance", "struct_puissance.html", null ],
      [ "sdlJeu", "structsdl_jeu.html", null ],
      [ "Terrain", "struct_terrain.html", null ]
    ] ],
    [ "Index des classes", "classes.html", null ],
    [ "Membres de classe", "functions.html", null ],
    [ "Liste des fichiers", "files.html", [
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/code_origine/main.cpp", "main_8cpp.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/deplacement_pion.c", "deplacement__pion_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/deplacement_pion.h", "deplacement__pion_8h.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/initialisation.c", "initialisation_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/initialisation.h", "initialisation_8h.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/interface_graphique.c", "interface__graphique_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/interface_graphique.h", "interface__graphique_8h.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/Jeu.c", "_jeu_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/Jeu.h", "_jeu_8h.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/joueur.c", "joueur_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/joueur.h", "joueur_8h.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/main (copie).c", "main_01_07copie_08_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/main.c", "main_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/Puissance.c", "_puissance_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/Puissance.h", "_puissance_8h.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/sdlJeu.c", "sdl_jeu_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/sdlJeu.h", "sdl_jeu_8h.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/Terrain.c", "_terrain_8c.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/Terrain.h", "_terrain_8h.html", null ],
      [ "/home/the-king/Projet_LIF7/jeu-puissance/Init_prog_puissance/src/Jeu_Puissance4/main2222.cpp", "main2222_8cpp.html", null ]
    ] ],
    [ "Répertoires", "dirs.html", [
      [ "code_origine", "dir_a2fac9b21386a9f136def0e96aa6dace.html", null ],
      [ "src", "dir_1a002551cb025d7028ee7405c206196b.html", [
        [ "Jeu_Puissance4", "dir_0d0d224ce6bd7f4244a28cb93aaaffdd.html", null ]
      ] ]
    ] ],
    [ "Membres de fichier", "globals.html", null ]
  ] ]
];

function createIndent(o,domNode,node,level)
{
  if (node.parentNode && node.parentNode.parentNode)
  {
    createIndent(o,domNode,node.parentNode,level+1);
  }
  var imgNode = document.createElement("img");
  if (level==0 && node.childrenData)
  {
    node.plus_img = imgNode;
    node.expandToggle = document.createElement("a");
    node.expandToggle.href = "javascript:void(0)";
    node.expandToggle.onclick = function() 
    {
      if (node.expanded) 
      {
        $(node.getChildrenUL()).slideUp("fast");
        if (node.isLast)
        {
          node.plus_img.src = node.relpath+"ftv2plastnode.png";
        }
        else
        {
          node.plus_img.src = node.relpath+"ftv2pnode.png";
        }
        node.expanded = false;
      } 
      else 
      {
        expandNode(o, node, false);
      }
    }
    node.expandToggle.appendChild(imgNode);
    domNode.appendChild(node.expandToggle);
  }
  else
  {
    domNode.appendChild(imgNode);
  }
  if (level==0)
  {
    if (node.isLast)
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2plastnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2lastnode.png";
        domNode.appendChild(imgNode);
      }
    }
    else
    {
      if (node.childrenData)
      {
        imgNode.src = node.relpath+"ftv2pnode.png";
      }
      else
      {
        imgNode.src = node.relpath+"ftv2node.png";
        domNode.appendChild(imgNode);
      }
    }
  }
  else
  {
    if (node.isLast)
    {
      imgNode.src = node.relpath+"ftv2blank.png";
    }
    else
    {
      imgNode.src = node.relpath+"ftv2vertline.png";
    }
  }
  imgNode.border = "0";
}

function newNode(o, po, text, link, childrenData, lastNode)
{
  var node = new Object();
  node.children = Array();
  node.childrenData = childrenData;
  node.depth = po.depth + 1;
  node.relpath = po.relpath;
  node.isLast = lastNode;

  node.li = document.createElement("li");
  po.getChildrenUL().appendChild(node.li);
  node.parentNode = po;

  node.itemDiv = document.createElement("div");
  node.itemDiv.className = "item";

  node.labelSpan = document.createElement("span");
  node.labelSpan.className = "label";

  createIndent(o,node.itemDiv,node,0);
  node.itemDiv.appendChild(node.labelSpan);
  node.li.appendChild(node.itemDiv);

  var a = document.createElement("a");
  node.labelSpan.appendChild(a);
  node.label = document.createTextNode(text);
  a.appendChild(node.label);
  if (link) 
  {
    a.href = node.relpath+link;
  } 
  else 
  {
    if (childrenData != null) 
    {
      a.className = "nolink";
      a.href = "javascript:void(0)";
      a.onclick = node.expandToggle.onclick;
      node.expanded = false;
    }
  }

  node.childrenUL = null;
  node.getChildrenUL = function() 
  {
    if (!node.childrenUL) 
    {
      node.childrenUL = document.createElement("ul");
      node.childrenUL.className = "children_ul";
      node.childrenUL.style.display = "none";
      node.li.appendChild(node.childrenUL);
    }
    return node.childrenUL;
  };

  return node;
}

function showRoot()
{
  var headerHeight = $("#top").height();
  var footerHeight = $("#nav-path").height();
  var windowHeight = $(window).height() - headerHeight - footerHeight;
  navtree.scrollTo('#selected',0,{offset:-windowHeight/2});
}

function expandNode(o, node, imm)
{
  if (node.childrenData && !node.expanded) 
  {
    if (!node.childrenVisited) 
    {
      getNode(o, node);
    }
    if (imm)
    {
      $(node.getChildrenUL()).show();
    } 
    else 
    {
      $(node.getChildrenUL()).slideDown("fast",showRoot);
    }
    if (node.isLast)
    {
      node.plus_img.src = node.relpath+"ftv2mlastnode.png";
    }
    else
    {
      node.plus_img.src = node.relpath+"ftv2mnode.png";
    }
    node.expanded = true;
  }
}

function getNode(o, po)
{
  po.childrenVisited = true;
  var l = po.childrenData.length-1;
  for (var i in po.childrenData) 
  {
    var nodeData = po.childrenData[i];
    po.children[i] = newNode(o, po, nodeData[0], nodeData[1], nodeData[2],
        i==l);
  }
}

function findNavTreePage(url, data)
{
  var nodes = data;
  var result = null;
  for (var i in nodes) 
  {
    var d = nodes[i];
    if (d[1] == url) 
    {
      return new Array(i);
    }
    else if (d[2] != null) // array of children
    {
      result = findNavTreePage(url, d[2]);
      if (result != null) 
      {
        return (new Array(i).concat(result));
      }
    }
  }
  return null;
}

function initNavTree(toroot,relpath)
{
  var o = new Object();
  o.toroot = toroot;
  o.node = new Object();
  o.node.li = document.getElementById("nav-tree-contents");
  o.node.childrenData = NAVTREE;
  o.node.children = new Array();
  o.node.childrenUL = document.createElement("ul");
  o.node.getChildrenUL = function() { return o.node.childrenUL; };
  o.node.li.appendChild(o.node.childrenUL);
  o.node.depth = 0;
  o.node.relpath = relpath;

  getNode(o, o.node);

  o.breadcrumbs = findNavTreePage(toroot, NAVTREE);
  if (o.breadcrumbs == null)
  {
    o.breadcrumbs = findNavTreePage("index.html",NAVTREE);
  }
  if (o.breadcrumbs != null && o.breadcrumbs.length>0)
  {
    var p = o.node;
    for (var i in o.breadcrumbs) 
    {
      var j = o.breadcrumbs[i];
      p = p.children[j];
      expandNode(o,p,true);
    }
    p.itemDiv.className = p.itemDiv.className + " selected";
    p.itemDiv.id = "selected";
    $(window).load(showRoot);
  }
}

