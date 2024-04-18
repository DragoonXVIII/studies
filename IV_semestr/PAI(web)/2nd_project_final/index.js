function updateLocalStorage() {
  let tasks = [];
  $(".card").each(function () {
    let task = {
      title: $(this).find("h3").text(),
      description: $(this).find("p").eq(0).text(),
      language: $(this).find("img").attr("alt"),
      hasDeadline: $(this).find("p").length > 2,
      deadline: $(this).find("p").eq(1).text().replace("Deadline: ", ""),
      purpose: $(this)
        .find("p")
        .eq(-1)
        .text()
        .replace("Purpose: ", "")
        .toLowerCase(),
      done: $(this).hasClass("card-done"),
    };
    tasks.push(task);
  });
  localStorage.setItem("tasks", JSON.stringify(tasks));
}

function handleRemove() {
  $(this).parent().remove();
  updateLocalStorage();
}

function handleCheckClick() {
  let parent = $(this).parent();

  if (parent.hasClass("card")) {
    parent.addClass("card-done");
    parent.find("p").css("text-decoration", "line-through");
    parent.find(".gg-trash").css("display", "block");
    $(this).css("display", "none");
  } else {
    // Extract values from the form within the modal
    let title = parent.find(".title-input").val();
    let description = parent.find(".desc-input").val();
    let language = parent.find(".language-combo").val();
    let hasDeadline = parent.find(".deadline-checkbox").prop("checked");
    let deadline = parent.find(".form-control").val();
    let purpose = parent.find('input[name="purpose"]:checked').val();

    if (title.length === 0) {
      alert("Please enter the title.");
      return;
    }

    if (description.length === 0) {
      alert("Please enter the description.");
      return;
    }

    if (hasDeadline) {
      if(!Date.parse(deadline))
      {
        alert("Please enter a valid date.");
        return;
      }
      if (new Date(deadline) < new Date()) {
        alert("Please enter a future date.");
        return;
      }
    }

    createNewCard(
      title,
      description,
      language,
      hasDeadline,
      deadline,
      purpose,
      false
    );

    // Clear all input values
    parent.find("input[type='text']").val("");
    parent.find("textarea").val("");
    parent.find(".form-control").val("");
    parent.find(".deadline-checkbox").prop("checked", false);
    parent.find(".form-control").hide();
  }
  updateLocalStorage();
}

function createNewCard(
  title,
  description,
  language,
  hasDeadline,
  deadline,
  purpose,
  done
) {
  let newCardCode = '<div class="card">';
  switch (language) {
    case "qt":
      newCardCode +=
        '<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/qt/qt-original.svg" alt="qt"/>';
      break;
    case "python":
      newCardCode +=
        '<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/python/python-original.svg" alt="python"/>';
      break;
    case "c++":
      newCardCode +=
        '<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg" alt="c++"/>';
      break;
    case "java":
      newCardCode +=
        '<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/java/java-original.svg" alt="java"/>';
      break;
    case "ruby":
      newCardCode +=
        '<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/ruby/ruby-original.svg" alt="ruby"/>';
      break;
  }
  newCardCode += `<div><h3>${title}</h3><p>${description}</p><br />`;
  if (hasDeadline) newCardCode += `<p>Deadline: ${deadline}</p>`;
  newCardCode += `<p>Purpose: ${purpose}</p></div><i class="gg-check-o"></i><i class="gg-trash"></i></div>`;

  //podczas ladowania strony, zeby zlaadowac zrobione tez juz karty
  newCard = $(newCardCode);
  if (done) {
    newCard.addClass("card-done");
    newCard.find("p").css("text-decoration", "line-through");
    newCard.find(".gg-trash").css("display", "block");
    newCard.find(".gg-check-o").css("display", "none");
  }

  $("main").append(newCard);
  $(".overlay").css("display", "none");
  newCard.find(".gg-check-o").click(handleCheckClick);
  newCard.find(".gg-trash").click(handleRemove);
}

$(document).ready(function () {
  $(".gg-check-o").click(handleCheckClick);
  //$(".gg-trash").click(handleRemove);
  $(".gg-close-o").click(function () {
    $(".overlay").css("display", "none");
  });

  $(".plus-button").click(function () {
    $(".overlay").css("display", "flex");
    $(".form-control").hide();
  });

  $(".deadline-checkbox").change(function () {
    if ($(this).prop("checked")) {
      $(this).closest(".modal").find(".form-control").show();
    } else {
      $(this).closest(".modal").find(".form-control").hide();
    }
  });

  let savedTasks = localStorage.getItem("tasks");
  if (savedTasks) {
    savedTasks = JSON.parse(savedTasks);
    savedTasks.forEach(function (task) {
      createNewCard(
        task.title,
        task.description,
        task.language,
        task.hasDeadline,
        task.deadline,
        task.purpose,
        task.done
      );
    });
  }
});
