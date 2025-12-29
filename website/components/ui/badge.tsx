export const Badge = ({ text = "Macro" }) => {
    let colorClass = "";

    if (text === "Macro") {
        colorClass = "bg-purple-100 text-purple-800 dark:bg-purple-900 dark:text-purple-300";
    } else if (text === "Function") {
        colorClass = "bg-blue-100 text-blue-800 dark:bg-blue-900 dark:text-blue-300";
    } else if (text === "Variable") {
        colorClass = "bg-orange-100 text-orange-800 dark:bg-orange-900 dark:text-orange-300";
    } else {
        colorClass = "bg-gray-100 text-gray-800 dark:bg-gray-900 dark:text-gray-300";
    }

    return (
    <span className={`ml-2 align-middle text-xs font-medium px-2 py-0.5 rounded ${colorClass}`}>
        {text}
    </span>
    );
};